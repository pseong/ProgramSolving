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
    ll n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pll> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.rbegin(), v.rend());
    vector<ll> ans1, ans2;
    for (int i=0; i<n; i++) {
        ll x = ((ll)ans1.size() + 1) * s1 * v[i].first;
        ll y = ((ll)ans2.size() + 1) * s2 * v[i].first;
        if (x >= y) ans2.push_back(v[i].second);
        else ans1.push_back(v[i].second);
    }
    cout << ans1.size() << ' ';
    for (auto x : ans1) cout << x << ' ';
    cout << '\n' << ans2.size() << ' ';
    for (auto x : ans2) cout << x << ' ';
    cout << '\n';
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