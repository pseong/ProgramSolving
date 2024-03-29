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
    const int inf = 10000000;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, inf));
    for (int i=1; i<=n; i++) {
        v[i][i] = 0;
    }
    vector<ti> edges;
    for (int i=0; i<m; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        v[s][e] = min(v[s][e], l);
        v[e][s] = min(v[e][s], l);
        edges.push_back({s, e, l});
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    pair<int, double> ans {-1, 10000000};
    for (int i=1; i<=n; i++) {
        double mx = 0;
        for (auto [s, e, l] : edges) {
            if (v[i][s] > v[i][e]) swap(s, e);
            mx = max(mx, v[i][e] + double(l - (v[i][e] - v[i][s])) / 2);
        }
        if (ans.second > mx) {
            ans.first = i;
            ans.second = mx;
        }
    }
    cout << fixed << setprecision(1) << ans.second << '\n';
}