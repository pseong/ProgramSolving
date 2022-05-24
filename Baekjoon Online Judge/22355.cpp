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

ll op(ll a, ll b) {
    return a + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<ll> an(n), up(n), down(n);

    for (int i=0; i<n; i++) cin >> an[i];
    for (int i=0; i<n; i++) cin >> up[i];
    for (int i=0; i<n; i++) cin >> down[i];

    Lazyseg mul(op, 100000, 0);
    Lazyseg add(op, 100000, 0);

    int i = 0;

    ll ans = 1000000000000000000;
    for (; i<k; i++) {
        mul.update_range(1, an[i]-1, -down[i]);
        add.update_range(1, an[i]-1, an[i]*down[i]);
        mul.update_range(an[i], 100000, up[i]);
        add.update_range(an[i], 100000, -an[i]*up[i]);
    }
    while (true) {
        int lo = 1;
        int hi = 100000;
        while (lo + 3 <= hi) {
            int l = (lo*2+hi)/3;
            int r = (lo+hi*2)/3;
            ll lcal = mul.query(l, l) * l + add.query(l, l);
            ll rcal = mul.query(r, r) * r + add.query(r, r);
            if (lcal < rcal) hi = r;
            else lo = l;
        }
        ll res = 1000000000000000000;
        for (int x=lo; x<=hi; x++) {
            ll M = mul.query(x, x);
            ll A = add.query(x, x);
            res = min(res, M * x + A);
        }
        ans = min(ans, res);

        if (i >= n) break;
        mul.update_range(1, an[i]-1, -down[i]);
        add.update_range(1, an[i]-1, an[i]*down[i]);
        mul.update_range(an[i], 100000, up[i]);
        add.update_range(an[i], 100000, -an[i]*up[i]);

        mul.update_range(1, an[i-k]-1, down[i-k]);
        add.update_range(1, an[i-k]-1, -an[i-k]*down[i-k]);
        mul.update_range(an[i-k], 100000, -up[i-k]);
        add.update_range(an[i-k], 100000, an[i-k]*up[i-k]);
        i++;
    }
    cout << ans;
}