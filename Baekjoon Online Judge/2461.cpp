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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    multiset<ti> st;
    for (int i=0; i<n; i++) {
        st.insert({v[i][0], i, 0});
    }
    int ans = 1e9;
    while (st.size()) {
        ans = min(ans, get<0>(*st.rbegin()) - get<0>(*st.begin()));
        auto [x, i, j] = *st.begin();
        st.erase(st.begin());
        if (j + 1 < m) st.insert({v[i][j + 1], i, j + 1});
        else break;
    }
    cout << ans << '\n';
}