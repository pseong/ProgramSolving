#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

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