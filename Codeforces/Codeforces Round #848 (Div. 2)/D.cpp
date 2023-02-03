#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

ll mod = 998244353;

ll powll(ll x, ll y) {
    if (y == 0) return 0;
    else if (y == 1) return x;
    ll r = powll(x, y/2) % mod;
    r *= r;
    r %= mod;
    if (y%2 == 1) r = (r * x) % mod;
    return r % mod;
}

void solve(int CASE) {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int x = 0;
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) x++;
    }
    vector<ll> dp(n + 1);
    dp[n] = 1;
    for (ll i=n-1; i>=1; i--) {
        dp[i] = ((n + (n-i)*dp[i+1] % mod) % mod) * powll(i, mod-2) % mod;
    }
    ll ans = 0;
    for (int i=1; i<=x; i++) {
        ans += dp[i];
        ans %= mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}