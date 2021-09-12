#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][1001]{0};
int dp[1001][1001]{0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];
        }
    }

    dp[1][1] = map[1][1];
    
    for(int k=2; k<=max(n,m); k++) {
        for(int i=1; i<=k; i++) {
            if(k<=n) dp[k][i] = max({dp[k-1][i]+map[k][i], dp[k][i-1]+map[k][i], dp[k-1][i-1]+map[k][i]});
            if(k<=m) dp[i][k] = max({dp[i-1][k]+map[i][k], dp[i][k-1]+map[i][k], dp[i-1][k-1]+map[i][k]});
        }
        if(k<=min(n,m)) dp[k][k] = max({dp[k-1][k]+map[k][k], dp[k][k-1]+map[k][k], dp[k-1][k-1]+map[k][k]});
        if(dp[n][m]) break;
    }

    cout << dp[n][m];
}