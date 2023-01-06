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

void solve(int CASE) {
    ll n, m;
    cin >> n >> m;
    vector<ll> dp(n + 1);
    for (ll i=n; i>1; i--) {
        dp[i] = (n / i - 1) * (n / i) / 2;
        for (ll j=i*2; j<=n; j+=i) {
            dp[i] -= dp[j];
        }
    }
    ll ans = 0;
    for (ll i=n; i>1; i--) {
        ll need = min(dp[i], m);
        ans += need / (i - 1) * i;
        m -= need / (i - 1) * (i - 1);
    }
    if (m) ans = -1;
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