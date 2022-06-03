#include <bits/stdc++.h>
using namespace std;

struct Lazyseg {
	// EDIT TYPE
	typedef struct {
		long long sum;
	} _T;
	typedef struct {
        long long a, b;
    } _L;
	_T op(_T a, _T b) {
		return { a.sum + b.sum };
	}

    //
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T t;
	Lazyseg(int n, _T t) : n(n), t(t) {
		S.resize(4*n+10, {0});
		lazy.resize(4*n+10, {1, 0});
	}
	Lazyseg(const vector<long long>& A, int n, _T t) : n(n), t(t) {
		S.resize(4*n+10, {0});
		lazy.resize(4*n+10, {1, 0});
		init(A, 1, 1, n);
	}
	_T init(const vector<long long>& A, int node, int s, int e) {
		if (s == e) {
			S[node].sum = A[s];
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(init(A, node*2, s, mid), init(A, node*2+1, mid+1, e));
	}
	void propagate(int node, int s, int e) {
		if (lazy[node].a == 1 && lazy[node].b == 0) return;
        // EDIT HERE
        S[node].sum *= lazy[node].a;
        S[node].sum += ((long long)e-s+1)*lazy[node].b;
        if (s!=e) {
            lazy[node*2].a *= lazy[node].a;
            lazy[node*2].b = lazy[node].a*lazy[node*2].b + lazy[node].b;
            lazy[node*2+1].a *= lazy[node].a;
            lazy[node*2+1].b = lazy[node].a*lazy[node*2+1].b + lazy[node].b;
        }
        //
		lazy[node].a = 1;
        lazy[node].b = 0;
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
	void update_range(int node, int s, int e, int l, int r, long long x) {
        propagate(node, s, e);
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			// EDIT HERE
			lazy[node].b += x;
            //
			propagate(node, s, e);
			return;
		}
		int mid = (s + e) / 2;
		update_range(node*2, s, mid, l, r, x);
		update_range(node*2+1, mid+1, e, l, r, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void update_range(int l, int r, long long x) {
		update_range(1, 1, n, l, r, x);
	}
	void set_range(int node, int s, int e, int l, int r, long long x) {
        propagate(node, s, e);
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			// EDIT HERE
			lazy[node].a = 0;
            lazy[node].b = x;
            //
			propagate(node, s, e);
			return;
		}
		int mid = (s + e) / 2;
		set_range(node*2, s, mid, l, r, x);
		set_range(node*2+1, mid+1, e, l, r, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void set_range(int l, int r, long long x) {
		set_range(1, 1, n, l, r, x);
	}
};