struct SetUpdateMaxSum {
	typedef struct {
		ll sum;
	} _T;
	typedef struct {
        ll a, b;
    } _L;
	_T op(_T a, _T b) {
		return { a.sum + b.sum };
	}
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T t;
	Lazyseg() {}
	Lazyseg(int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, { 0 });
		lazy.assign(4*n+10, { 1, 0 });
	}
	Lazyseg(const vector<ll>& A, int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, { 1, 0 });
		_init(A, 1, 1, n);
	}
	void init(int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, { 0 });
		lazy.assign(4*n+10, { 1, 0 });
	}
	void init(const vector<ll>& A, int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, { 1, 0 });
		_init(A, 1, 1, n);
	}
	_T _init(const vector<ll>& A, int node, int s, int e) {
		if (s == e) {
			S[node].sum = A[s];
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(init(A, node*2, s, mid), init(A, node*2+1, mid+1, e));
	}
	void propagate(int node, int s, int e) {
		if (lazy[node].a == 1 && lazy[node].b == 0) return;
        S[node].sum *= lazy[node].a;
        S[node].sum += ((ll)e-s+1)*lazy[node].b;
        if (s!=e) {
            lazy[node*2].a *= lazy[node].a;
            lazy[node*2].b = lazy[node].a*lazy[node*2].b + lazy[node].b;
            lazy[node*2+1].a *= lazy[node].a;
            lazy[node*2+1].b = lazy[node].a*lazy[node*2+1].b + lazy[node].b;
        }
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
	void update_range(int node, int s, int e, int l, int r, ll x) {
        propagate(node, s, e);
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			lazy[node].b += x;
			propagate(node, s, e);
			return;
		}
		int mid = (s + e) / 2;
		update_range(node*2, s, mid, l, r, x);
		update_range(node*2+1, mid+1, e, l, r, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void update_range(int l, int r, ll x) {
		update_range(1, 1, n, l, r, x);
	}
	void set_range(int node, int s, int e, int l, int r, ll x) {
        propagate(node, s, e);
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			lazy[node].a = 0;
            lazy[node].b = x;
			propagate(node, s, e);
			return;
		}
		int mid = (s + e) / 2;
		set_range(node*2, s, mid, l, r, x);
		set_range(node*2+1, mid+1, e, l, r, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void set_range(int l, int r, ll x) {
		set_range(1, 1, n, l, r, x);
	}
};