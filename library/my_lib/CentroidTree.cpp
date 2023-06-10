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
		for (auto nxt : adj[cent]) {
			if (!disabled[nxt]) init(nxt, cent);
		}
	}
};