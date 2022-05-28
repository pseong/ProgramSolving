#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll mod = 998244353;

ll dp[1010][5050];
ll pref[1010][5050];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=1; i<=m; i++) {
        dp[1][i] = 1;
        pref[1][i] += pref[1][i-1] + 1;
    }

    for (int i=2; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (j-k >= 0) dp[i][j] += (pref[i-1][j-k] - pref[i-1][0] + mod);
            dp[i][j] %= mod;
            if (j+k-1 <= m) dp[i][j] += (pref[i-1][m] - pref[i-1][j+k-1] + mod);
            dp[i][j] %= mod;
            if (k == 0) dp[i][j] -= dp[i-1][j];
            dp[i][j] += mod;
            dp[i][j] %= mod;
            pref[i][j] = pref[i][j-1] + dp[i][j];
            pref[i][j] %= mod;
        }
    }

    ll ans = 0;
    for (int j=1; j<=m; j++) {
        ans += dp[n][j];
        ans %= mod;
    }
    cout << ans;
}