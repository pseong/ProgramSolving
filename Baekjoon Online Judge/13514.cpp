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

int n, parent[101010][20], d[101010];
vector<int> adj[101010];

struct CentroidTree {
	vector<int> sz, par, disabled;
	CentroidTree(size_t _sz) : sz(_sz), par(_sz), disabled(_sz) {}
	int getSize(int cur, int prev) {
		sz[cur] = 1;
		for (auto nxt : adj[cur]) {
			if (disabled[nxt] || nxt == prev) continue;
			sz[cur] += getSize(nxt, cur);
		}
		return sz[cur];
	}
	int getCent(int cur, int prev, int cnt) {
		for (auto nxt : adj[cur]) {
			if (disabled[nxt] || nxt == prev) continue;
			if (sz[nxt] * 3 > cnt) return getCent(nxt, cur, cnt);
		}
		return cur;
	}
	void init(int cur, int prev = 0) {
		int cnt = getSize(cur, prev);
		int cent = getCent(cur, prev, cnt);
		if (prev == 0) par[cent] = cent;
		else par[cent] = prev;
		disabled[cent] = 1;
		for (auto nxt : adj[cent]) {
			if (!disabled[nxt]) init(nxt, cent);
		}
	}
};

CentroidTree CT(101010);

void dfs(int x, int p, int depth) {
    d[x] = depth;
    parent[x][0] = p;
    for (int y : adj[x]) {
        if (y == p) continue;
        dfs(y, x, depth + 1);
    }
}

void precal_lca() {
    dfs(1, 0, 0);
    for (int j=1; j<20; j++) {
        for (int i=1; i<=n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i=19; i>=0; i--) {
        if (d[x] - d[y] >= (1<<i)) x = parent[x][i];
    }

    if (x == y) return x;

    for (int i=19; i>=0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[y][0];
}

int dist(int u, int v) {
    return d[u] + d[v] - 2*d[lca(u,v)];
}

int chk[101010];
multiset<int> ms[101010];

void update(int x) {
    chk[x] ^= 1;
    int i = x;
    while (1) {
        int dst = dist(i, x);
        if (chk[x]) ms[i].insert(dst);
        else ms[i].erase(ms[i].find(dst));
        if (i == CT.par[i]) break;
        i = CT.par[i];
    }
};

const int inf = 1e9;

int query(int x) {
    int ret = inf, i = x;
    while (1) {
        int dst = dist(i, x);
        if (!ms[i].empty()) ret = min(ret, dst + *ms[i].begin());
        if (i == CT.par[i]) break;
        i = CT.par[i];
    }
    return ret == inf ? -1 : ret;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    precal_lca();

    CT.init(2);
    int q;
    cin >> q;
    while (q--) {
        int what, x;
        cin >> what >> x;
        if (what == 1) update(x);
        else cout << query(x) << '\n';
    }
}