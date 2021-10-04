#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    char an[120][120]{0};
    char an2[120][120]{0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> an[i][j];
            an2[i][j] = an[i][j];
            if(an2[i][j]=='R') an2[i][j] = 'G';
        }
    }

    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};

    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(an[i][j]!='0') {
                cnt++;
                char f=an[i][j];
                queue<pii> q;
                q.push({i, j});
                an[i][j] = '0';
                while(!q.empty()) {
                    int a, b;
                    tie(a, b) = q.front();
                    q.pop();
                    for(int d=0; d<4; d++) {
                        int x=a+dx[d];
                        int y=b+dy[d];
                        if(x<0||x>=n||y<0||y>=n) continue;
                        if(an[x][y]==f) {
                            an[x][y] = '0';
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }

    int cnt2=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(an2[i][j]!='0') {
                cnt2++;
                char f=an2[i][j];
                queue<pii> q;
                q.push({i, j});
                an2[i][j] = '0';
                while(!q.empty()) {
                    int a, b;
                    tie(a, b) = q.front();
                    q.pop();
                    for(int d=0; d<4; d++) {
                        int x=a+dx[d];
                        int y=b+dy[d];
                        if(an2[x][y]==f) {
                            an2[x][y] = '0';
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }

    cout << cnt << ' ' << cnt2;
}