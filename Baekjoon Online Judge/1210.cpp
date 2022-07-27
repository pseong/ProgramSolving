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

vector<int> adj[440];
ll c[440][440], f[440][440], d[440];
int s = 2001;
int t = 2002;
int bias = 200;

ll maxFlow() {
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
        ll flow = LONG_LONG_MAX;
        for (int x=t; x!=s; x=d[x]) {
            flow = min(flow, c[d[x]][x] - f[d[x]][x]);
        }
        for (int x=t; x!=s; x=d[x]) {
            f[d[x]][x] += flow;
            f[x][d[x]] -= flow;
        }
        ans += flow;
    }
    return ans;
}

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    cin >> s >> t;
    t += bias;
    for (int i=1; i<=n; i++) {
        adj[i].push_back(i+bias);
        adj[i+bias].push_back(i);
        cin >> c[i][i+bias];
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a+bias].push_back(b);
        adj[b].push_back(a+bias);
        adj[b+bias].push_back(a);
        adj[a].push_back(b+bias);
        c[a+bias][b] = LONG_LONG_MAX;
        c[b+bias][a] = LONG_LONG_MAX;
    }
    maxFlow();
    vector<int> chk(1000);
    queue<int> q;
    q.push(s);
    chk[s] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (chk[y] == 0 && c[x][y]- f[x][y] > 0) {
                chk[y] = 1;
                q.push(y);
            }
        }
    }
    vector<int> ans;
    for (int i=1; i<=n; i++) {
        if (chk[i] == 1 && chk[i+bias] == 0) ans.push_back(i);
    }
    for (int x : ans) {
        cout << x << ' ';
    }
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}