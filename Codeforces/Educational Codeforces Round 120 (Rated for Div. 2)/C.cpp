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

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n+1), pref(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i=1; i<=n; i++) {
        pref[i] = pref[i-1] + v[i];
    }
    ll ans = 1e18;
    for (int i=0; i<n; i++) {
        ll x = pref[n] - pref[n-i] - v[1]*i;
        ll cnt = (pref[n] - x - k + i) / (1 + i);
        if (cnt < 0) cnt = 0;
        ans = min(ans, cnt + i);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}