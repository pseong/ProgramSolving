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

int n, m, s, t;
vector<vector<pi>> adj;
vector<vector<pi>> hist;

void solve() {
    int inf = 1e9;
    adj.assign(n, vector<pi>());
    hist.assign(n, vector<pi>());
    for (int i=0; i<m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        adj[u].push_back({v, p});
    }
    vector<int> dist(n, inf);
    priority_queue<pi> q;
    dist[s] = 0;
    q.push({0, s});
    while (q.size()) {
        auto [d, x] = q.top();
        d = -d;
        q.pop();
        if (dist[x] < d) continue;
        for (int i=0; i<(int)adj[x].size(); i++) {
            auto [y, d2] = adj[x][i];
            if (dist[y] > d + d2) {
                hist[y].clear();
                hist[y].push_back({x, i});
                dist[y] = d + d2;
                q.push({-(d + d2), y});
            }
            else if (dist[y] == d + d2) {
                hist[y].push_back({x, i});;
            }
        }
    }
    if (dist[t] == inf) {
        cout << -1 << '\n';
        return;
    }
    queue<int> que;
    vector<int> chk(n);
    que.push(t);
    chk[t] = 1;
    while (que.size()) {
        int a = que.front();
        que.pop();
        for (auto [x, i] : hist[a]) {
            adj[x][i].second = -1;
            if (chk[x] == 0) {
                chk[x] = 1;
                que.push(x);
            }
        }
    }
    dist.assign(n, inf);
    dist[s] = 0;
    q.push({0, s});
    while (q.size()) {
        auto [d, x] = q.top();
        d = -d;
        q.pop();
        if (dist[x] < d) continue;
        for (auto [y, d2] : adj[x]) {
            if (d2 == -1) continue;
            if (dist[y] > d + d2) {
                dist[y] = d + d2;
                q.push({-(d + d2), y});
            }
        }
    }
    if (dist[t] == inf) cout << -1 << '\n';
    else cout << dist[t] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> t;
        solve();
    }
}