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

vector<int> adj[1010];
int c[1010][1010], f[1010][1010], lv[1010], work[1010];
const int s = 1001;
const int t = 1002;

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

void solve(int CASE) {
    int n;
    cin >> n;
    int sum = 0;
    int sum2 = 0;
    for (int i=1; i<=n; i++) {
        adj[s].push_back(i);
        adj[i].push_back(s);
        cin >> c[s][i];
        sum += c[s][i];
    }
    for (int i=1; i<=n; i++) {
        adj[i+500].push_back(t);
        adj[t].push_back(i+500);
        cin >> c[i+500][t];
        sum2 += c[i+500][t];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            adj[i].push_back(j+500);
            adj[j+500].push_back(i);
            c[i][j+500] = 1;
        }
    }
    int flow = maxFlow();
    if (flow != sum || sum != sum2) {
        cout << -1 << '\n';
        return;
    }
    cout << 1 << '\n';
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << f[i][j+500];
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve(1);
}