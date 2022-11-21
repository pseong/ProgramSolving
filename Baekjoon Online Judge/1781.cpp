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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pll> v(n);
    ll now = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        now = max(now, v[i].first);
    }
    sort(v.begin(), v.end());
    priority_queue<int> p;
    ll ans = 0;
    int i = n-1;
    while (now > 0) {
        auto [d, c] = v[i];
        if (p.empty()) now = d;
        while (i>=0 && v[i].first >= now) {
            p.push(v[i].second);
            i--;
        }
        if (p.size()) {
            ans += p.top();
            p.pop();
            now--;
        }
    }
    cout << ans << '\n';
}