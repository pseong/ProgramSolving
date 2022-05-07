#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

struct Lazyseg {
	//EDIT TYPE
	typedef int _T;
	typedef int _L;
    //
	int n = 250000;
	_T S[1010101];
	_L lazy[1010101];
	_T t = 0;

    _T op(_T a, _T b) {
        return max(a, b);
    }
    
	void clear() {
		memset(S, 0, sizeof S);
        memset(lazy, 0, sizeof lazy);
	}
	void propagate(int node, int s, int e) {
		if (lazy[node] == 0) return;
        // EDIT HERE
        S[node] += lazy[node];
        if (s!=e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        //
		lazy[node] = 0;
	}
	_T query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
		if (e < l || r < s) return t;
		if (l <= s && e <= r) return S[node];
		int mid = (s+e)/2;
		return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
	}
	_T query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	void update_range(int node, int s, int e, int l, int r, _L x) {
        propagate(node, s, e);
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			// EDIT HERE
			lazy[node] += x;
            //
			propagate(node, s, e);
			return;
		}
		int mid = (s + e) / 2;
		update_range(node*2, s, mid, l, r, x);
		update_range(node*2+1, mid+1, e, l, r, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void update_range(int l, int r, _L x) {
		update_range(1, 1, n, l, r, x);
	}
} seg;

struct E {
    int op, x, y, c;
    bool operator < (const E& e) {
        int a = -op;
        int b = -e.op;
        return tie(x, a) < tie(e.x, b);
    }
};

vector<E> v;
int n, k;
int X[101010], Y[101010], C[101010];
multiset<int> ms[252525];

bool cal(int R) {
    v.clear();
    seg.clear();
    for (int i=1; i<=k; i++) ms[i] = multiset<int>{-500000, 500000};

    for (int i=0; i<n; i++) {
        v.push_back({1, X[i], Y[i], C[i]});
        v.push_back({-1, X[i]+R, Y[i], C[i]});
    }
    sort(v.begin(), v.end());

    for (E e : v) {
        if (e.op == 1) {
            auto it = ms[e.c].insert(e.y);
            int l = max(e.y, *prev(it) + R + 1);
            l = max(l, 1);
            int r = min(e.y + R, *next(it) - 1);
            r = min(r, 250000);
            seg.update_range(l, r, 1);
            int a = seg.query(1, 250000);
            if (seg.query(1, 250000) == k) return true;
        }
        else {
            auto it = ms[e.c].lower_bound(e.y);
            int l = max(e.y, *prev(it) + R + 1);
            l = max(l, 1);
            int r = min(e.y + R, *next(it) - 1);
            r = min(r, 250000);
            seg.update_range(l, r, -1);
            ms[e.c].erase(it);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> X[i] >> Y[i] >> C[i];
    }

    int lo = 0;
    int hi = 250000;
    int ans = 250000;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        bool b = cal(mid);
        if (cal(mid)) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans;
}