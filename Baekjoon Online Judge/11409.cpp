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

vector<pi> adj[1010];
int c[1010][1010], f[1010][1010], d[1010], cost[1010];
int inQ[1010];
int s = 1001;
int t = 1002;
int bias = 400;
const int inf = 1010101010;

pi maxFlow() {
    pi ans = {0, 0};
    while (true) {
        memset(d, -1, sizeof d);
        for (int i=0; i<1010; i++) {
            cost[i] = inf;
        }
        queue<int> q;
        q.push(s);
        inQ[s] = true;
        cost[s] = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            inQ[x] = false;
            for (auto [y, w] : adj[x]) {
                int a = cost[y];
                int b = cost[x] + w;
                if (cost[y] > cost[x] + w && c[x][y] - f[x][y] > 0) {
                    cost[y] = cost[x] + w;
                    d[y] = x;
                    if (inQ[y]) continue;
                    inQ[y] = true;
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
        ans.first += flow;
        ans.second += cost[t];
    }
    return ans;
}

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        adj[s].push_back({i, 0});
        adj[i].push_back({s, 0});
        c[s][i] = 1;
    }
    for (int i=1; i<=n; i++) {
        int z;
        cin >> z;
        while (z--) {
            int j, w;
            cin >> j >> w;
            j += bias;
            adj[i].push_back({j, -w});
            adj[j].push_back({i, w});
            c[i][j] = 1;
        }
    }
    for (int i=1; i<=m; i++) {
        int j = i + bias;
        adj[j].push_back({t, 0});
        adj[t].push_back({j, 0});
        c[j][t] = 1;
    }
    pi ans = maxFlow();
    cout << ans.first << '\n' << -ans.second << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}