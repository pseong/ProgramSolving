#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

struct Lazyseg {
	//EDIT TYPE
	typedef long long _T;
	typedef long long _L;
    //
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T(*op)(_T, _T);
	_T t;
	Lazyseg(_T(*op)(_T, _T), int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, 0);
		lazy.resize(4*n+10, 0);
	}
	Lazyseg(const vector<_T>& A, _T(*op)(_T, _T), int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, 0);
		lazy.resize(4*n+10, 0);
		init(A, 1, 1, n);
	}
	_T init(const vector<_T>& A, int node, int s, int e) {
		if (s == e) return S[node] = A[s];
		int mid = (s+e)/2;
		return S[node] = op(init(A, node*2, s, mid), init(A, node*2+1, mid+1, e));
	}
	void propagate(int node, int s, int e) {
		if (lazy[node] == 0) return;
        // EDIT HERE
        S[node] += ((_T)e-s+1)*lazy[node];
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
};

struct Point {
    ll idx, x, y;
};

vector<Point> points;
ll cnt[202020][2];
int n;
const ll mod = 1e9+7;

bool comp(Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool comp2(Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x > b.x;
}

ll op(ll a, ll b) {
    return a + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        x += 202020;
        y += 202020;
        points.push_back({i, x, y});
    }
    sort(points.begin(), points.end(), comp);
    Lazyseg seg(op, 404040, 0);
    for (Point p : points) {
        cnt[p.idx][0] = seg.query(p.y+1, 404040);
        seg.update_range(p.y, p.y, 1);
    }

    sort(points.begin(), points.end(), comp2);
    Lazyseg seg2(op, 404040, 0);
    for (Point p : points) {
        cnt[p.idx][1] = seg2.query(p.y+1, 404040);
        seg2.update_range(p.y, p.y, 1);
    }

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += cnt[i][0] * cnt[i][1] % mod;
        ans %= mod;
    }
    cout << ans;
}