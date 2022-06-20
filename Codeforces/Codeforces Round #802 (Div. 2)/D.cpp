#include <bits/stdc++.h>
#define int long long
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
    int n; cin >> n;
    vector<ll> v(n+1), pref(n+1);
    ll mx = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
        mx = max(mx, (pref[i] + i - 1) / i );
    }

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t < mx) cout << -1 << '\n';
        else cout << (pref[n] + t - 1) / t << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}