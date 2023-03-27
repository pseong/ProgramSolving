/*
Empty Subarray는 고려하지 않는다.
*/
struct DynamicMaxSubarraySum {
	typedef struct {
		ll lval, rval, val, all;
	} _T;
	int n;
	_T t = {(ll)-1e18, (ll)-1e18, (ll)-1e18, 0};
	vector<_T> S;
    _T op(_T left, _T right) {
        return {
            max(left.lval, left.all + right.lval),
            max(right.rval, left.rval + right.all),
            max({left.val, right.val, left.rval + right.lval}),
            left.all + right.all,
        };
    }
	DynamicMaxSubarraySum() {}
	DynamicMaxSubarraySum(int n) : n(n) {
		S.assign(4*n+10, {0});
	}
	DynamicMaxSubarraySum(const vector<ll>& A, int n) : n(n) {
		S.assign(4*n+10, {0});
		_init(A, 1, 1, n);
	}
	void init(int n) {
		this->n = n;
		S.assign(4*n+10, {0});
	}
	void init(const vector<ll>& A, int n) {
		this->n = n;
		S.assign(4*n+10, {0});
		_init(A, 1, 1, n);
	}
	_T _init(const vector<ll>& A, int node, int s, int e) {
		if (s == e) {
            S[node].lval = A[s];
            S[node].rval = A[s];
            S[node].val = A[s];
            S[node].all = A[s];
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(_init(A, node*2, s, mid), _init(A, node*2+1, mid+1, e));
	}
	_T query(int node, int s, int e, int l, int r) {
		if (e < l || r < s) return t;
		if (l <= s && e <= r) return S[node];
		int mid = (s+e)/2;
		return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
	}
	_T query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	void update(int node, int s, int e, int p, ll x) {
		if (p < s || e < p) return;
		if (s == e) {
            S[node].all = x;
            S[node].lval = x;
            S[node].rval = x;
            S[node].val = x;
			return;
		}
		int mid = (s + e) / 2;
		update(node*2, s, mid, p, x);
		update(node*2+1, mid+1, e, p, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void update(int p, ll x) {
		update(1, 1, n, p, x);
	}
};