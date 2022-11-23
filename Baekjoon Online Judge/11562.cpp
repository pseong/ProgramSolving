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
    vector<vector<int>> w(n + 1, vector<int>(n + 1, inf));
    for (int i=1; i<=n; i++) {
        w[i][i] = 0;
    }
    for (int i=0; i<m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        w[u][v] = 0;
        w[v][u] = 0;
        if (b == 0) w[v][u] = 1;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int s, e;
        cin >> s >> e;
        cout << w[s][e] << '\n';
    }
}