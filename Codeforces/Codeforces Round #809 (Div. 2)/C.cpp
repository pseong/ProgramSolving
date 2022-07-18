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
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    if (n <= 2) {
        cout << 0 << '\n';
        return;
    }

    vector<ll> dp1(n+1), dp2(n+1);
    for (int i=2; i<=n; i+=2) {
        dp1[i] = dp1[i-2];
        if (v[i-1] > v[i-2] && v[i-1] > v[i]) continue;
        ll mx = max(v[i-2], v[i]);
        dp1[i] += mx - v[i-1] + 1;
    }
    for (int i=3; i<=n; i+=2) {
        dp2[i] = dp2[i-2];
        if (v[i-1] > v[i-2] && v[i-1] > v[i]) continue;
        ll mx = max(v[i-2], v[i]);
        dp2[i] += mx - v[i-1] + 1;
    }
    if (n%2 == 1) {
        cout << dp2[n] << '\n';
        return;
    }

    ll ans = LONG_LONG_MAX - 10000;
    for (int i=1; i<=n; i+=2) {
        ans = min(ans, dp2[i] + dp1[n] - dp1[i+1]);
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