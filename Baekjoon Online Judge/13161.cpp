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

vector<int> adj[550];
int c[550][550], f[550][550], level[550], work[550], chk[550];
const int S = 501;
const int T = 502;
const int inf = 1e9+1000;

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

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            c[S][i] = inf;
            adj[S].push_back(i);
            adj[i].push_back(S);
        }
        else if (x == 2) {
            c[i][T] = inf;
            adj[i].push_back(T);
            adj[T].push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c[i][j];
            if (i != j) adj[i].push_back(j);
        }
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
    cout << ans << '\n';

    queue<int> q;
    q.push(S);
    chk[S] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (!chk[y] && c[x][y] - f[x][y] > 0) {
                chk[y] = 1;
                q.push(y);
            }
        }
    }

    vector<int> A, B;
    for (int i=1; i<=n; i++) {
        if (chk[i]) A.push_back(i);
        else B.push_back(i);
    }
    for (int x : A) cout << x << ' ';
    cout << '\n';
    for (int x : B) cout << x << ' ';
    cout << '\n';
}