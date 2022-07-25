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
// 애드몬드 카프 알고리즘
vector<int> adj[440];
int c[440][440], f[440][440], d[440];
const int s = 1;
const int t = 2;

int main() {
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
    while (true) {
        memset(d, -1, sizeof d);
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (d[y] == -1 && c[x][y] - f[x][y] > 0) {
                    d[y] = x;
                    q.push(y);
                }
            }
        }
        if (d[t] == -1) break;
        int flow = INT_MAX;
        for (int x=t; x!=s; x=d[x]) {
            flow = min(flow, c[d[x]][x] - f[d[x]][x]);
        }
        for (int x=t; x!=s; x=d[x]) {
            f[d[x]][x] += flow;
            f[x][d[x]] -= flow;
        }
        ans += flow;
    }
    cout << ans << '\n';
}
*/

/*
// 디닉 알고리즘
vector<int> adj[440];
int c[440][440], f[440][440], lv[440], work[440];
const int s = 1;
const int t = 2;

bool bfs() {
    memset(lv, -1, sizeof lv);
    lv[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();s
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
                f[x][y] += flow;
                f[y][x] -= flow;
                return ret;
            }
        }
    }
    return 0;
}

int main() {
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
            int flow = dfs(s, INT_MAX);
            if (flow == 0) break;
            ans += flow;
        }
    }
    cout << ans << '\n';
}
*/