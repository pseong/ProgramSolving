#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll dp[3030][3030];
ll sum[3030][3030];
int cnt[] { 1, 10, 100, 1000, 10000 };

int f(int x) {
    if (x < 10) return 2;
    if (x < 100) return 3;
    if (x < 1000) return 4;
    else return 5;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p; cin >> n >> p;

    for (int i=1; i<=n; i++) {
        dp[i][f(i)] = 26;
    }
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=n; i++) {
            sum[i][j] = sum[i-1][j] + dp[i][j];
            sum[i][j] %= p;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=4; k++) {
                if (j-k-1 < 1) continue;
                int x = max(i-cnt[k-1], 0);
                int y = max(i-cnt[k], 0);
                dp[i][j] += (sum[x][j-k-1] - sum[y][j-k-1] + p)*25;
                dp[i][j] %= p;
            }
            sum[i][j] = sum[i-1][j] + dp[i][j];
            sum[i][j] %= p;
        }
    }
    
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += dp[n][i];
        ans %= p;
    }
    cout << ans << '\n';
}