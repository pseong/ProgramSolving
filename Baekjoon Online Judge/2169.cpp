#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int mp[1010][1010];
int dp[3][1010][1010];

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0; i<1010; i++) {
        for (int j=0; j<1010; j++) {
            for (int k=0; k<3; k++) {
                dp[k][i][j] = -1000000000;
            }
        }
    }

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> mp[i][j];
        }
    }

    dp[0][1][0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[0][i][j] = max(dp[2][i-1][j], dp[0][i][j-1]) + mp[i][j];
        }
        for (int j=m; j>=1; j--) {
            dp[1][i][j] = max(dp[2][i-1][j], dp[1][i][j+1]) + mp[i][j];
        }
        for (int j=1; j<=m; j++) {
            dp[2][i][j] = max(dp[0][i][j], dp[1][i][j]);
        }
    }
    cout << dp[2][n][m];
}