#include <bits/stdc++.h>
using namespace std;
using ll=long long;

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

const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    cin >> m;
    DynamicMaxSubarraySum seg(a, n);
    for (int i=0; i<m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 < x2) {
            ll ans = seg.query(1, 1, n, y1+1, x2-1).all
                    + seg.query(1, 1, n, x1, y1).rval
                    + seg.query(1, 1, n, x2, y2).lval;
            cout << ans << '\n';
        }
        else {
            auto mid = seg.query(1, 1, n, x2, y1);
            auto l = seg.query(1, 1, n, x1, x2-1);
            auto r = seg.query(1, 1, n, y1+1, y2);

            ll ans = max({
                mid.val,
                mid.all + l.rval + r.lval,
                mid.lval + l.rval,
                mid.rval + r.lval
            });
            cout << ans << '\n';
        }
    }
}