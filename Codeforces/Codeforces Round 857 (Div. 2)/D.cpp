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

bool comp(pi a, pi b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

void solve(int CASE) {
    int n;
    cin >> n;
    vector<pi> v(n);
    multiset<int> ms;
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        ms.insert(v[i].second);
    }
    sort(v.begin(), v.end(), comp);
    int mx = -2e9;
    int ans = 2e9;
    for (int i=0; i<n; i++) {
        auto [x, y] = v[i];
        ms.erase(ms.find(y));
        auto it = ms.lower_bound(x);
        int a = mx;
        int b = mx;
        if (it != ms.end()) a = max(a, *it);
        if (it != ms.begin()) {
            it--;
            b = max(b, *it);
        }
        ans = min(ans, min(abs(x - a), abs(x - b)));
        mx = max(mx, y);
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