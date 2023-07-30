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
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    int idx = max_element(v.begin() + 1, v.end()) - v.begin();
    int idx2 = min_element(v.begin() + 1, v.end()) - v.begin();
    vector<pi> ans;
    if (v[idx] > 0) {
        for (int i=0; i<7; i++) ans.push_back({idx, idx});
        ans.push_back({n, idx});
        for (int i=0; i<3; i++) ans.push_back({n, n});
        for (int i=1; i<n; i++) {
            ans.push_back({i, n});
            ans.push_back({n, n});
        }
        ans.push_back({n, n});
    }
    else {
        for (int i=0; i<7; i++) ans.push_back({idx2, idx2});
        ans.push_back({1, idx2});
        for (int i=0; i<3; i++) ans.push_back({1, 1});
        for (int i=n; i>1; i--) {
            ans.push_back({i, 1});
            ans.push_back({1, 1});
        }
        ans.push_back({1, 1});
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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