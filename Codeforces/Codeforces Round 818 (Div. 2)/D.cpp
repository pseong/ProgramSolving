#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll mod = 1e9 + 7;
const ll MAX = 101010;
ll fact[MAX], p[MAX];

ll powll(int n, int r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    ll x = powll(n, r/2);
    if (r%2 == 0) return x * x % mod;
    else return x * x % mod * n % mod;
}

ll comb(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * p[n-r] % mod * p[r] % mod;
}

void init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    for (int i=0; i<MAX; i++) {
        p[i] = powll(fact[i], mod-2);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int i=0; i<=min(n, k); i++) {
        ans += comb(n, i);
        ans %= mod;
    }
    cout << ans << '\n';
}