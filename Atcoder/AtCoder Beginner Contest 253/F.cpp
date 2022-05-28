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
 
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(q), b(q), c(q), d(q), last(n+1, -1), x(n+1);
    vector<pll> past;
    for (int i=0; i<q; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            cin >> b[i] >> c[i] >> d[i];
        }
        else if (a[i] == 2) {
            cin >> b[i] >> c[i];
            last[b[i]] = i;
            x[b[i]] = c[i];
        }
        else {
            cin >> b[i] >> c[i];
            if (last[b[i]] != -1) past.push_back({last[b[i]], c[i]});
        }
    }
    sort(past.rbegin(), past.rend());
 
    last.assign(n+1, -1);
    x.assign(n+1, 0);
    map<pll, ll> mp;
    Lazyseg seg(op, 200000, 0);
    for (int i=0; i<q; i++) {
        if (a[i] == 1) {
            seg.update_range(b[i], c[i], d[i]);
        }
        else if (a[i] == 2) {
            last[b[i]] = i;
            x[b[i]] = c[i];
            while (past.size() && past.back().first == i) {
                ll f, s;
                tie(f, s) = past.back();
                past.pop_back();
                ll re = seg.query(s, s);
                mp[{f, s}] = re;
            }
        }
        else if (a[i] == 3) {
            if (last[b[i]] != -1) cout << x[b[i]] + seg.query(c[i], c[i]) - mp[{last[b[i]], c[i]}] << '\n';
            else cout << seg.query(c[i], c[i]) << '\n';
        }
    }
}