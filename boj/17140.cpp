#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int an[101][101]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int r, c, k;
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin >> an[i][j];
        }
    }
    int col=3;
    int row=3;
    int t=0;
    while(true) {
        if(an[r][c]==k) break;
        if(t>=100) {
            t=-1;
            break;
        }
        if(col>=row) {
            int new_row=0;
            for(int i=1; i<=col; i++) {
                int cnt[101]{0};
                for(int j=1; j<=row; j++) {
                    if(an[i][j]>0) cnt[an[i][j]]++;
                }
                vector<pair<int, int>> v;
                for(int c=1; c<=100; c++) {
                    if(cnt[c]>0) {
                        v.push_back({cnt[c], c});
                    }
                }
                int sz=v.size();
                new_row = max(new_row, sz*2);
                if(new_row>100) new_row = 100;
                sort(v.begin(), v.end());
                for(int c=0; c<sz; c++) {
                    if(c==50) break;
                    an[i][c*2+1] = v[c].second;
                    an[i][c*2+2] = v[c].first;
                }
                for(int c=2*sz+1; c<=100; c++) {
                    an[i][c] = 0;
                }
            }
            row = new_row;
        }
        else {
            int new_col=0;
            for(int j=1; j<=row; j++) {
                int cnt[101]{0};
                for(int i=1; i<=col; i++) {
                    if(an[i][j]>0) cnt[an[i][j]]++;
                }
                vector<pair<int, int>> v;
                for(int c=1; c<=100; c++) {
                    if(cnt[c]>0) {
                        v.push_back({cnt[c], c});
                    }
                }
                int sz=v.size();
                new_col = max(new_col, sz*2);
                if(new_col>100) new_col = 100;
                sort(v.begin(), v.end());
                for(int c=0; c<sz; c++) {
                    if(c==50) break;
                    an[c*2+1][j] = v[c].second;
                    an[c*2+2][j] = v[c].first;
                }
                for(int c=2*sz+1; c<=100; c++) {
                    an[c][j] = 0;
                }
            }
            col = new_col;
        }
        t++;
    }
    cout << t;
}