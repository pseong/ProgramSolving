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

vector<int> adj[55];
int c[55][55], f[55][55], lv[55], work[55];
int s = 2001;
int t = 2002;
int u, v, w;

bool bfs() {
    memset(lv, -1, sizeof lv);
    lv[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (x == u && y == v || x == v && y == u) continue;
            if (lv[y] == -1 && c[x][y] - f[x][y] > 0) {
                lv[y] = lv[x] + 1;
                q.push(y);
            }
        }
    }
    return lv[t] != -1;
}

int dfs(int x, int flow) {
    if (x == t) return flow;
    for (int& i=work[x]; i<(int)adj[x].size(); i++) {
        int y = adj[x][i];
        if (x == u && y == v || x == v && y == u) continue;
        if (lv[y] == lv[x] + 1 && c[x][y] - f[x][y] > 0) {
            int ret = dfs(y, min(flow, c[x][y] - f[x][y]));
            if (ret > 0) {
                f[x][y] += ret;
                f[y][x] -= ret;
                return ret;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int ans = 0;
    while (bfs()) {
        memset(work, 0, sizeof work);
        while (true) {
            int flow = dfs(s, INT_MAX);
            if (flow == 0) break;
            ans += flow;
        }
    }
    return ans;
}

vector<ti> edges;
int sum;

int chk() {
    memset(f, 0, sizeof f);
    int ans = maxFlow();
    vector<int> chk(100);
    queue<int> q;
    q.push(s);
    chk[s] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (x == u && y == v || x == v && y == u) continue;
            if (chk[y] == 0 && c[x][y] - f[x][y] > 0) {
                chk[y] = 1;
                q.push(y);
            }
        }
    }
    if (chk[u] == chk[v]) return 0;
    return sum - ans;
}

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] = w;
        c[v][u] = w;
        sum += w;
    }
    cin >> s >> t;
    int ans = 0;
    for (int i=0; i<m; i++) {
        auto [uu, vv, ww] = edges[i];
        u = uu;
        v = vv;
        w = ww;
        ans = max(ans, chk());
    }
    cout << ans << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}