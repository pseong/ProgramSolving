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
    vector<pi> v;
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());
    vector<pi> ans;
    for (auto [l, r] : v) {
        if (ans.empty()) {
            ans.push_back(v.front());
            continue;
        }
        if (ans.back().second < l) {
            ans.push_back({l, r});
        }
        else {
            ans.back().second = max(ans.back().second, r);
        }
    }
    for (auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}