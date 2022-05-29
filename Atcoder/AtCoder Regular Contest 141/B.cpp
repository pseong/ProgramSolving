#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll mod = 998244353;
ll dp[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    if (n >= 70) {
        cout << 0;
        return 0;
    }
    ll x = 1;
    int cnt = 0;
    while ((x<<1) <= m) {
        x <<= 1;
        cnt++;
    }
    for (int i=0; i<cnt; i++) {
        dp[0][i] = 1LL<<i;
        dp[0][i] %= mod;
    }
    dp[0][cnt] = m-x+1;
    dp[0][cnt] %= mod;
    for (int i=1; i<n; i++) {
        for (int j=i; j<=cnt; j++) {
            ll z = 1LL<<j;
            if (j == cnt) z = m-x+1;
            z %= mod;
            for (int k=0; k<j; k++) {
                dp[i][j] += z * dp[i-1][k];
                dp[i][j] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int i=0; i<=cnt; i++) {
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout << ans;
}
