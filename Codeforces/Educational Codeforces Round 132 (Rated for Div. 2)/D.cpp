#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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

struct Lazyseg {
	// EDIT TYPE
	typedef struct {
		long long mx;
	} _T;
	typedef long long _L;
    //
    _T(*op)(_T, _T);
	int n;
	vector<_T> S;
	_T t;
	Lazyseg(_T(*op)(_T, _T), int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, {0});
	}
	Lazyseg(_T(*op)(_T, _T), const vector<long long>& A, int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, {0});
		init(A, 1, 1, n);
	}
	_T init(const vector<long long>& A, int node, int s, int e) {
		if (s == e) {
			S[node].mx = A[s];
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
};

Lazyseg::_T op(Lazyseg::_T a, Lazyseg::_T b) {
    return { max(a.mx, b.mx) };
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> v(m+1);
    for (int i=1; i<=m; i++) {
        cin >> v[i];
    }
    int q;
    cin >> q;
    Lazyseg seg(op, v, m, { 0 });
    for (int Q=1; Q<=q; Q++) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        ll mx = seg.query(min(y, b), max(y, b)).mx;
        if (mx < max(x, a)) {
            if (abs(b-y)%k == 0 && abs(a-x)%k == 0) yes();
            else no();
        }
        else if (mx >= max(x, a)) {
            ll h = (mx-x)/k*k + k + x;
            if (abs(b-y)%k == 0 && abs(a-x)%k == 0 && h <= n) yes();
            else no();
        }
    }
}