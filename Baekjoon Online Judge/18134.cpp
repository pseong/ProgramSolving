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

struct MCMF {
    struct Edge {
        int y, c, f, w, rev;
    };
    vector<vector<Edge>> adj;
    int n, s, t;
    const int inf = 1010101010;

    MCMF(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n+1, vector<Edge>());
    }

    void addEdge(int x, int y, int c, int w) {
        adj[x].push_back({y, c, 0, w, (int)adj[y].size()});
        adj[y].push_back({x, 0, 0, -w, (int)adj[x].size()-1});
    }

    pll maxFlow() {
        pll ans = {0, 0};
        while (true) {
            vector<int> dv(n+1, -1), didx(n+1, -1), inQ(n+1);
            vector<ll> cost(n+1, inf);
            queue<ll> q;
            q.push(s);
            inQ[s] = 1;
            cost[s] = 0;
            while (q.size()) {
                ll x = q.front();
                q.pop();
                inQ[x] = 0;
                for (int i=0; i<(int)adj[x].size(); i++) {
                    Edge& e = adj[x][i];
                    if (cost[e.y] > cost[x] + e.w && e.c - e.f > 0) {
                        cost[e.y] = cost[x] + e.w;
                        dv[e.y] = x;
                        didx[e.y] = i;
                        if (inQ[e.y]) continue;
                        inQ[e.y] = 1;
                        q.push(e.y);
                    }
                }
            }
            if (didx[t] == -1) break;
            int flow = inf;
            for (int x=t; x!=s; x=dv[x]) {
                flow = min(flow, adj[dv[x]][didx[x]].c - adj[dv[x]][didx[x]].f);
            }
            for (ll x=t; x!=s; x=dv[x]) {
                ans.second += (ll)adj[dv[x]][didx[x]].w * flow;
                adj[dv[x]][didx[x]].f += flow;
                adj[x][adj[dv[x]][didx[x]].rev].f -= flow;
            }
            ans.first += flow;
        }
        return ans;
    }
};

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    MCMF mcmf(n*2+1, 0, n*2+1);
    int bias = n;
    for (int i=0; i<m; i++) {
        int w, a, b;
        cin >> w >> a >> b;
        mcmf.addEdge(a+bias, b, 1, w);
        mcmf.addEdge(b+bias, a, 1, w);
    }
    for (int i=1; i<=n; i++) {
        mcmf.addEdge(i, i+bias, 1, 0);
    }
    int x, y;
    cin >> x >> y;
    mcmf.addEdge(mcmf.s, x+bias, 2, 0);
    mcmf.addEdge(y, mcmf.t, 2, 0);
    pll ans = mcmf.maxFlow();
    for (auto a : mcmf.adj[y]) {
        if (a.y == mcmf.t) {
            if (a.f != 2) {
                cout << -1 << '\n';
                return;
            }
            else break;
        }
    }
    cout << ans.second << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}