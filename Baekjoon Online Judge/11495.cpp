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

vector<int> adj[2626];
int c[2626][2626], f[2626][2626], lv[2626], work[2626];
const int s = 2600;
const int t = 2601;

bool bfs() {
    memset(lv, -1, sizeof lv);
    lv[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
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

int n, m;
int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};

int conv(int x, int y) {
    return x*m + y + 1;
}

void solve(int CASE) {
    cin >> n >> m;
    memset(c, 0, sizeof c);
    memset(f, 0, sizeof f);
    for (int i=0; i<2626; i++) {
        adj[i].clear();
    }

    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x = conv(i, j);
            if ((i+j)%2 == 0) {
                adj[s].push_back(x);
                adj[x].push_back(s);
                c[s][x] = v[i][j];

                for (int d=0; d<4; d++) {
                    int x = i+dx[d];
                    int y = j+dy[d];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    int from = conv(i, j);
                    int to = conv(x, y);
                    adj[from].push_back(to);
                    adj[to].push_back(from);
                    c[from][to] = 10000;
                }
            }
            else {
                adj[x].push_back(t);
                adj[t].push_back(x);
                c[x][t] = v[i][j];
            }
        }
    }
    int flow = maxFlow();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x = conv(i, j);
            if ((i+j)%2 == 0) {
                flow += c[s][x] - f[s][x];
            }
            else {
                flow += c[x][t] - f[x][t];
            }
        }
    }
    cout << flow << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}