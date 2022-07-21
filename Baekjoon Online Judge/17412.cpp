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

/*
vector<int> adj[440];
int c[440][440], f[440][440], d[440];

void solve() {
    int n, p;
    cin >> n >> p;
    for (int i=0; i<p; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] = 1;
    }

    int ans = 0;
    while (true) {
        memset(d, -1, sizeof d);
        queue<int> q;
        q.push(1);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    d[y] = x;
                    q.push(y);
                    if (y == 2) break;
                }
            }
        }
        if (d[2] == -1) break;
        int flow = 10;
        for (int i=2; i!=1; i=d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        for (int i=2; i!=1; i=d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        ans += flow;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

*/

vector<int> adj[440];
int c[440][440], f[440][440], level[440], work[440];
const int S = 1;
const int T = 2;
const int inf = 100000;

bool bfs() {
    memset(level, -1, sizeof level);
    level[S] = 0;
    queue<int> q;
    q.push(S);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (level[y] == -1 && c[x][y] - f[x][y] > 0) {
                level[y] = level[x] + 1;
                q.push(y);
            }
        }
    }
    return level[T] != -1;
}

int dfs(int x, int flow) {
    if (x == T) return flow;
    for (int& i=work[x]; i<adj[x].size(); i++) {
        int y = adj[x][i];
        if (level[y] == level[x] + 1 && c[x][y] - f[x][y] > 0) {
            int ret = dfs(y, min(c[x][y] - f[x][y], flow));
            if (ret > 0) {
                f[x][y] += ret;
                f[y][x] -= ret;
                return ret;
            }
        }
    }
    return 0;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;
    for (int i=0; i<p; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] = 1;
    }

    int ans = 0;
    while (bfs()) {
        memset(work, 0, sizeof work);
        while (true) {
            int flow = dfs(S, inf);
            if (flow == 0) break;
            ans += flow;
        }
    }
    cout << ans;
}