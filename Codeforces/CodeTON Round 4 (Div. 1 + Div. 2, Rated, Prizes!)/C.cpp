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
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> v(n + 1);
    map<ll, ll> mp;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll ans = 0;
    if (mp.count(1) == 0) {
        ans += d;
        mp[1] = 1;
    }
    for (auto [x, y] : mp) {
        if (y > 1) {
            ans += c * (y - 1);
        }
    }
    set<ll> st;
    for (auto [x, y] : mp) st.insert(x);

    ll cnt = 0;
    ll now = 1;
    ll no = 2;
    ll res = 1e18;
    bool ok = true;
    for (auto x : st) {
        cnt++;
        if (x == now) {
            now++;
            continue;
        }
        if (x != now) {
            res = min(res, ans + ((ll)st.size() - (cnt - 1)) * c);
            ans += (x - now) * d;
            now = x + 1;
        }
    }
    cout << min(ans, res) << '\n';
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