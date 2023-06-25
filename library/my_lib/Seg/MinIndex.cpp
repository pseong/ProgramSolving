struct MinIndex {
	typedef struct {
		ll mx;
	} _T;
    _T op(_T a, _T b) {
    	return { max(a.mx, b.mx) };
	}
	int n;
	vector<_T> S;
	_T t;
	MinIndex() {}
	MinIndex(int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, { 0 });
	}
	MinIndex(const vector<ll>& A, int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, { 0 });
		_init(A, 1, 1, n);
	}
	void init(int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, { 0 });
	}
	void init(const vector<ll>& A, int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, { 0 });
		_init(A, 1, 1, n);
	}
	_T _init(const vector<ll>& A, int node, int s, int e) {
		if (s == e) {
			S[node].mx = A[s];
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(_init(A, node*2, s, mid), _init(A, node*2+1, mid+1, e));
	}
	ll query(int node, int s, int e, int l, int r, int c) {
		if (e < l || r < s) return t.mx;
		int mid = (s+e)/2;
        if (s == e) {
            if (S[node].mx >= c) return { s };
            else return t.mx;
        }
		if (l <= s && e <= r) {
            if (S[node*2].mx >= c) return query(node*2, s, mid, l, r, c);
            else if (S[node*2+1].mx >= c) return query(node*2+1, mid+1, e, l, r, c);
            else return t.mx;
        }
        return min(query(node*2, s, mid, l, r, c), query(node*2+1, mid+1, e, l, r, c));
	}
	ll query(int l, int r, int c) {
		return query(1, 1, n, l, r, c);
	}
};