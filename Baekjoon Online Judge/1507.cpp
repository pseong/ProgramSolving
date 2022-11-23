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

int cost[30][30];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ti> edges;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int a;
            cin >> a;
            if (i < j) {
                edges.push_back({a, i, j});
            }
        }
    }
    sort(edges.begin(), edges.end());
    const int inf = 10000000;
    vector<vector<int>> vv(n + 1, vector<int>(n + 1, inf));
    for (int i=1; i<=n; i++) {
        vv[i][i] = 0;
    }
    for (auto& [w, u, v] : edges) {
        auto go = vv;
        for (int k=1; k<=n; k++) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    go[i][j] = min(go[i][j], go[i][k] + go[k][j]);
                }
            }
        }
        if (go[u][v] > w) {
            vv[u][v] = w;
            vv[v][u] = w;
        }
        else if (go[u][v] < w) {
            cout << -1 << '\n';
            return 0;
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (vv[i][j] != inf) ans += vv[i][j];
        }
    }
    cout << ans / 2 << '\n';
}