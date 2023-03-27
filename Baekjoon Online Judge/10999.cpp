#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Lazyseg {
	//////////////////// EDIT TYPE
	typedef struct {
		long long sum;
	} _T;
	typedef struct {
		long long lz;
	} _L;
    ////////////////////
    _T(*op)(_T, _T);
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T t;
	Lazyseg() {}
	Lazyseg(_T(*op)(_T, _T), int n, _T t) : op(op), n(n), t(t) {
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, {0});
	}
	Lazyseg(_T(*op)(_T, _T), const vector<ll>& A, int n, _T t) : op(op), n(n), t(t) {
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, {0});
		_init(A, 1, 1, n);
	}
	void init(_T(*op)(_T, _T), int n, _T t) {
		this->op = op;
		this->n = n;
		this->t = t;
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, {0});
	}
	void init(_T(*op)(_T, _T), const vector<ll>& A, int n, _T t) {
		this->op = op;
		this->n = n;
		this->t = t;
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, {0});
		_init(A, 1, 1, n);
	}
	_T _init(const vector<ll>& A, int node, int s, int e) {
		if (s == e) {
			S[node].sum = A[s];
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(_init(A, node*2, s, mid), _init(A, node*2+1, mid+1, e));
	}
	void propagate(int node, int s, int e) {
		if (lazy[node].lz == 0) return;
        //////////////////// EDIT HERE
        S[node].sum += ((ll)e-s+1)*lazy[node].lz;
        if (s!=e) {
            lazy[node*2].lz += lazy[node].lz;
            lazy[node*2+1].lz += lazy[node].lz;
        }
		lazy[node].lz = 0;
        ////////////////////
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
			//////////////////// EDIT HERE
			lazy[node].lz += x.lz;
            ////////////////////
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

Lazyseg::_T op(Lazyseg::_T a, Lazyseg::_T b) {
    return { a.sum + b.sum };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }

    Lazyseg seg(op, v, n, { 0 });

    for (int i=0; i<m+k; i++) {
        int a;
        cin >> a;
        if (a==1) {
            int b, c;
            ll d;
            cin >> b >> c >> d;
            seg.update_range(b, c, { d });
        }
        else if (a==2) {
            int b, c;
            cin >> b >> c;
            cout << seg.query(b, c).sum << '\n';
        }
    }
    return 0;
}