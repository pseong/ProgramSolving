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

const int inf = 2e9;

int inter(pi a, pi b) {
    if (max(a.first, b.first) <= min(a.second, b.second)) {
        return min(a.second, b.second) - max(a.first, b.first) + 1;
    }
    else return 0;
}

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<pi> st, rst;
    vector<ti> tt;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        st.push_back({a, b});
        rst.push_back({-b, -a});
        tt.push_back({b-a+1, a, b});
    }
    sort(all(st));
    sort(all(rst));
    sort(all(tt));
    int ans = 0;
    for (auto [l, r] : st) {
        int mx = r - l + 1;
        auto [dup, x, y] = tt[0];
        int mn = dup - (mx - dup);
        ans = max(ans, mx - mn);
        auto it = lower_bound(st.begin(), st.end(), make_pair(r+1, -inf));
        auto it2 = lower_bound(rst.begin(), rst.end(), make_pair(-l+1, -inf));
        if (it != st.end()) ans = max(ans, mx*2);
        if (it != st.begin()) {
            auto [x, y] = *(--it);
            int dup = inter({l, r}, {x, y});
            int mn = dup - (mx - dup);
            ans = max(ans, mx - mn);
        }
        if (it2 != rst.end()) ans = max(ans, mx*2);
        if (it2 != rst.begin()) {
            auto [x, y] = *(--it2);
            int dup = inter({-r, -l}, {x, y});
            int mn = dup - (mx - dup);
            ans = max(ans, mx - mn);
        }
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