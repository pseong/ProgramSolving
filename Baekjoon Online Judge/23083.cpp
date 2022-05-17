#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int dp[1010][1010];
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int k; cin >> k;
    for (int i=0; i<k; i++) {
        int x, y; cin >> x >> y;
        dp[x][y] = -1;
    }
    dp[1][1] = 1;
    for (int j=1; j<=m; j++) {
        for (int i=1; i<=n; i++) {
            if (dp[i][j] == -1) continue;
            if (dp[i+1][j] != -1) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
            }
            if (dp[i][j+1] != -1) {
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= mod;
            }
            if (j%2 == 1 && dp[i-1][j+1] != -1) {
                dp[i-1][j+1] += dp[i][j];
                dp[i-1][j+1] %= mod;
            }
            if (j%2 == 0 && dp[i+1][j+1] != -1) {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= mod;
            }
        }
    }
    cout << dp[n][m];
}