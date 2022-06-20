#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }
 
ll powll(ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x % 998244353;
    ll a = powll(x, y/2);
    if (y%2 == 0) return a * a % 998244353;
    else return a * a * x % 998244353;
}

struct Lazyseg {
	// EDIT TYPE
	typedef struct {
		long long sum;
	} _T;
	typedef long long _L;
    //
    _T(*op)(_T, _T);
	int n;
	vector<_T> S;
	_T t;
	Lazyseg(_T(*op)(_T, _T), const vector<long long>& A, int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, {0});
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
	_T query(int node, int s, int e, int l, int r) {
		if (e < l || r < s) return t;
		if (l <= s && e <= r) return S[node];
		int mid = (s+e)/2;
		return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
	}
	_T query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	void update_range(int node, int s, int e, int l, int r, _L x) {
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			// EDIT HERE
            S[node].sum = { x };
            //
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
    return { (a.sum + b.sum) % 998244353 };
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    vector<ll> v1(n+1), v2(n+1), v3(n+1);
    for (int i=1; i<=n; i++) {
        v1[i] = v[i] * i % 998244353 * i % 998244353;
        v2[i] = v[i] * i % 998244353;
        v3[i] = v[i] % 998244353;
    }
    Lazyseg seg1(op, v1, n, { 0 });
    Lazyseg seg2(op, v2, n, { 0 });
    Lazyseg seg3(op, v3, n, { 0 });
    while (q--) {
        int what;
        cin >> what;
        if (what == 1) {
            ll x, v;
            cin >> x >> v;
            seg1.update_range(x, x, v * x % 998244353 * x % 998244353);
            seg2.update_range(x, x, v * x % 998244353);
            seg3.update_range(x, x, v % 998244353);
        }
        else {
            ll x;
            cin >> x;
            ll ans = (seg1.query(1, x).sum -(2*x+3)*seg2.query(1, x).sum + (x*x+3*x+2) % 998244353 * seg3.query(1, x).sum + (2*x+3)*998244353) % 998244353 * powll(2, 998244353-2) % 998244353;
            cout << ans << '\n';
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}