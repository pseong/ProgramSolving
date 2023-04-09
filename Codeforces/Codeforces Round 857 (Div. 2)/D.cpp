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

bool cmp(pi x, pi y) {
    if (x.first == y.first) return x.second < y.second;
    else return x.first > y.first;
}

void solve(int CASE) {
    int n;
    cin >> n;
    vector<pi> v(n + 1);
    multiset<int> ms;
    for (int i=1; i<=n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin() + 1, v.end(), cmp);
    for (int i=1; i<=n; i++) ms.insert(v[i].second);
    int ans = 1e9;
    int mx = -1e9;
    for (int i=1; i<=n; i++) {
        ms.erase(ms.find(v[i].second));
        auto it = ms.lower_bound(v[i].first);
        ans = min(ans, abs(v[i].first - mx));
        if (it != ms.end()) ans = min(ans, abs(v[i].first - max(mx, *it)));
        if (it != ms.begin()) ans = min(ans, abs(v[i].first - max(mx, *(--it))));
        mx = max(mx, v[i].second);
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