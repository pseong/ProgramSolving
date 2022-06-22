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

vector<int> adj[202020];
int dist[202020], d[202020], mark[202020];
const int inf = 1000000000;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        dist[i] = m;
    }
    for (int i=1; i<=m; i++) {
        int v, u;
        cin >> v >> u;
        adj[u].push_back(v);
        ++d[v];
    }

    dist[n] = 0;
    pqg<pi> pq;
    pq.push({0, n});
    while (pq.size()) {
        int x = pq.top().second;
        pq.pop();
        if (mark[x]) continue;
        mark[x] = 1;
        for (int y : adj[x]) {
            if (dist[x] + d[y] < dist[y]) {
                dist[y] = dist[x] + d[y];
                pq.push({dist[y], y});
            }
            --d[y];
        }
    }
    cout << dist[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}