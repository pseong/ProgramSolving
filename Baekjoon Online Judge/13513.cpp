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

int n, counT, parent[101010][20], d[101010], length[101010], chk[101010];
vector<pi> adj[101010];
map<int, multiset<int>> sub[101010];
multiset<int> submx[101010], can;

struct CentroidTree {
	vector<int> sz, par, disabled;
	CentroidTree(size_t _sz) : sz(_sz), par(_sz), disabled(_sz) {}
	int getSize(int cur, int prev) {
		sz[cur] = 1;
		for (auto [nxt, cnt] : adj[cur]) {
			if (disabled[nxt] || nxt == prev) continue;
			sz[cur] += getSize(nxt, cur);
		}
		return sz[cur];
	}
	int getCent(int cur, int prev, int cnt) {
		for (auto [nxt, dst] : adj[cur]) {
			if (disabled[nxt] || nxt == prev) continue;
			if (sz[nxt] * 2 > cnt) return getCent(nxt, cur, cnt);
		}
		return cur;
	}
	void init(int cur, int prev = 0) {
		int cnt = getSize(cur, prev);
		int cent = getCent(cur, prev, cnt);
		if (prev == 0) par[cent] = cent;
		else par[cent] = prev;
		disabled[cent] = 1;
		for (auto [nxt, cnt] : adj[cent]) {
			if (!disabled[nxt]) init(nxt, cent);
		}
	}
};

CentroidTree CT(101010);

void dfs(int x, int p, int depth, int l) {
    d[x] = depth;
    length[x] = l;
    parent[x][0] = p;
    for (auto [y, cnt] : adj[x]) {
        if (y == p) continue;
        dfs(y, x, depth + 1, l + cnt);
    }
}

void precal_lca() {
    dfs(1, 0, 0, 0);
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
    return length[u] + length[v] - 2*length[lca(u,v)];
}

void erase_mx(int i, int x) {
    if (submx[i].size() >= 2) {
        can.erase(can.find(*submx[i].rbegin() + *next(submx[i].rbegin())));
    }
    submx[i].erase(submx[i].find(x));
    if (submx[i].size() >= 2) {
        can.insert(*submx[i].rbegin() + *next(submx[i].rbegin()));
    }
}

void insert_mx(int i, int x) {
    if (submx[i].size() >= 2) {
        can.erase(can.find(*submx[i].rbegin() + *next(submx[i].rbegin())));
    }
    submx[i].insert(x);
    if (submx[i].size() >= 2) {
        can.insert(*submx[i].rbegin() + *next(submx[i].rbegin()));
    }
}

void update(int x) {
    chk[x] ^= 1;
    if (chk[x] == 1) {
        counT++;
        int i = x;
        int prev = i;
        while (1) {
            int dst = dist(i, x);
            int idx = prev;

            if (sub[i][idx].lower_bound(dst) == sub[i][idx].end()) {
                if (sub[i][idx].size()) erase_mx(i, *sub[i][idx].rbegin());
                sub[i][idx].insert(dst);
                insert_mx(i, *sub[i][idx].rbegin());
            }
            else {
                sub[i][idx].insert(dst);
            }

            if (i == CT.par[i]) break;
            prev = i;
            i = CT.par[i];
        }
    }
    else {
        counT--;
        int i = x;
        int prev = i;
        while (1) {
            int dst = dist(i, x);
            int idx = prev;

            int mx = *sub[i][idx].rbegin();
            sub[i][idx].erase(sub[i][idx].find(dst));
            if (sub[i][idx].lower_bound(mx) == sub[i][idx].end()) {
                erase_mx(i, mx);
                if (sub[i][idx].size()) insert_mx(i, *sub[i][idx].rbegin());
            }

            if (i == CT.par[i]) break;
            prev = i;
            i = CT.par[i];
        }
    }
};

const int inf = 1e9;

void query() {
    if (can.size()) cout << *can.rbegin() << '\n';
    else if (counT) cout << 0 << '\n';
    else cout << -1 << '\n';
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    precal_lca();
    CT.init(1);

    for (int i=1; i<=n; i++) update(i);

    int q;
    cin >> q;
    while (q--) {
        int what, x;
        cin >> what;
        if (what == 1) {
            cin >> x;
            update(x);
        }
        else query();
    }
}