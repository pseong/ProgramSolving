#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector<int> adj[202020];

struct Dsu {
    vector<int> parent;

    Dsu() {};
    Dsu(int n) {
        init(n);
    }
    void init(int n) {
        parent.resize(n+1);
        for (int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }
    int leader(int i) {
        if (parent[i] == i) return i;
        return parent[i] = leader(parent[i]);
    }
    int merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x > y) swap(x, y);
        return parent[y] = x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
} dsu;

vector<pi> edges;

void dfs(int x, int p) {
    for (int y : adj[x]) {
        if (y == p) continue;
        if (!dsu.same(x, y)) {
            edges.push_back({x, y});
            dsu.merge(x, y);
            dfs(y, x);
        }
    }
}

void ds(int x, int p) {
    vector<int> go;
    for (int y : adj[x]) {
        if (y == p) continue;
        if (!dsu.same(x, y)) {
            edges.push_back({x, y});
            dsu.merge(x, y);
            go.push_back(y);
        }
    }
    for (int y : go) {
        if (y == p) continue;
        ds(y, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dsu.init(n);
    dfs(1, 0);
    for (auto a : edges) {
        cout << a.first << ' ' << a.second << '\n';
    }
    dsu.init(n);
    edges.clear();
    ds(1, 0);
    for (auto a : edges) {
        cout << a.first << ' ' << a.second << '\n';
    }
}