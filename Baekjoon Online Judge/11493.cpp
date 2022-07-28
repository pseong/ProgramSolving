#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int inf = 1010101010;

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

void solve(ll CASE) {
    ll n, m;
    cin >> n >> m;
    MCMF mcmf(n+1, 0, n+1);
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        mcmf.addEdge(x, y, inf, 1);
        mcmf.addEdge(y, x, inf, 1);
    }
    vector<int> col(n+1), col2(n+1);
    for (int i=1; i<=n; i++) {
        cin >> col[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> col2[i];
    }
    for (int i=1; i<=n; i++) {
        if (col[i] == 0 && col2[i] == 1) {
            mcmf.addEdge(mcmf.s, i, 1, 0);
        }
        else if (col[i] == 1 && col2[i] == 0) {
            mcmf.addEdge(i, mcmf.t, 1, 0);
        }
    }
    cout << mcmf.maxFlow().second << '\n';
}

ll T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (ll t=1; t<=T; t++) {
        solve(t);
    }
}