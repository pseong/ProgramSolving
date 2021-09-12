#include <iostream>
#include <vector>

using namespace std;

int an[51][51]{0};
int dx[]{0, 0, -1, 1};
int dy[]{-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int air1{0};
    int air2{0};
    int r, c, t;
    cin >> r >> c >> t;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin >> an[i][j];
            if(an[i][j]==-1) {
                if(!air1) {
                    air1 = i;
                } else {
                    air2 = i;
                }
            }
        }
    }
    while(t--) {
        int plus[51][51]{0};
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=c; j++) {
                if(an[i][j]>4) {
                    int amt=an[i][j]/5;
                    for(int d=0; d<4; d++) {
                        int x=i+dx[d];
                        int y=j+dy[d];
                        if(x<1||x>r||y<1||y>c) continue;
                        if(an[x][y]==-1) continue;
                        plus[x][y] += amt;
                        an[i][j] -= amt;
                    }
                }
            }
        }
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=c; j++) {
                an[i][j] += plus[i][j];
            }
        }
        for(int i=air1-1; i>=2; i--) {
            an[i][1] = an[i-1][1];
        }
        for(int j=1; j<=c-1; j++) {
            an[1][j] = an[1][j+1];
        }
        for(int i=1; i<=air1-1; i++) {
            an[i][c] = an[i+1][c];
        }
        for(int j=c; j>=3; j--) {
            an[air1][j] = an[air1][j-1];
        }
        an[air1][2] = 0;
        for(int i=air2+1; i<=r-1; i++) {
            an[i][1] = an[i+1][1];
        }
        for(int j=1; j<=c-1; j++) {
            an[r][j] = an[r][j+1];
        }
        for(int i=r; i>=air2+1; i--) {
            an[i][c] = an[i-1][c];
        }
        for(int j=c; j>=3; j--) {
            an[air2][j] = an[air2][j-1];
        }
        an[air2][2] = 0;
    }
    int ans=0;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(an[i][j]>0) {
                ans += an[i][j];
            }
        }
    }
    cout << ans;
}