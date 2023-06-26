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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    vector<vector<ll>> v(2);
    for (int i=0; i<n; i++) v[a[i]].push_back(b[i]);
    srtrev(v[0]);
    srtrev(v[1]);
    ll ans = 0;
    for (int i=0; i<n; i++) ans += b[i];
    if (v[0].size() == v[1].size()) {
        for (auto x : v[0]) ans += x;
        for (auto x : v[1]) ans += x;
        ans -= min(v[0].back(), v[1].back());
        cout << ans << '\n';
    }
    else {
        int m = min(v[0].size(), v[1].size());
        for (int i=0; i<m; i++) ans += v[0][i];
        for (int i=0; i<m; i++) ans += v[1][i];
        cout << ans << '\n';
    }
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