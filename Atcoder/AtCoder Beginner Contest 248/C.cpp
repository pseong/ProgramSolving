#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int mod = 998244353;

int dp[100][2500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            for (int a=1; a<=m; a++) {
                if (j+a <= k) {
                    dp[i+1][j+a] += dp[i][j];
                    dp[i+1][j+a] %= mod;
                }
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=k; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans;
}