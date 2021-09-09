#include <iostream>
#include <cstring>

using namespace std;

int dx[]{0, 0, -1, 1};
int dy[]{-1, 1, 0, 0};
int dp[501][501]{0};
int an[501][501]{0};
int n, m;

int dfs(int i, int j) {
    int cnt=0;
    for(int d=0; d<4; d++) {
        int x=i+dx[d];
        int y=j+dy[d];
        if(x<1||x>n||y<1||y>m) continue;
        if(an[i][j] > an[x][y]) {
            if(dp[x][y] >=0) cnt += dp[x][y];
            else cnt += dfs(x, y);
        }
    }
    dp[i][j] = cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> an[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[n][m] = 1;
    int ans=dfs(1, 1);
    cout << dp[1][1];
}