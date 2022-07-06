#include <bits/stdc++.h>
#define int long long
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
    int n, x;
    cin >> n >> x;
    vector<int> v(n+1), g(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i] >> g[i];
    }
    ll ans = LONG_LONG_MAX;
    ll now = 0;
    for (int i=1; i<=min(n, x); i++) {
        now += (v[i] + g[i]);
        ll cnt = x - i;
        if (cnt < 0) break;
        ans = min(ans, now + g[i]*cnt);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}