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
		long long val, even, odd;
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
			S[node].val = A[s];
            S[node].odd = 0;
            S[node].even = 0;
            if (A[s] % 2 == 0) S[node].even = 1;
            else S[node].odd = 1;
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
	void update(int node, int s, int e, int p, _L x) {
		if (e < p || p < s) return;
		if (s == e) {
			S[node].val = x;
            S[node].odd = 0;
            S[node].even = 0;
            if (x % 2 == 0) S[node].even = 1;
            else S[node].odd = 1;
			return;
		}
		int mid = (s + e) / 2;
		update(node*2, s, mid, p, x);
		update(node*2+1, mid+1, e, p, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void update(int p, _L x) {
		update(1, 1, n, p, x);
	}
};

Lazyseg::_T op(Lazyseg::_T a, Lazyseg::_T b) {
    return { a.val + b.val, a.even + b.even, a.odd + b.odd };
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    Lazyseg seg(op, v, n, { 0 });
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what == 1) {
            int i, x;
            cin >> i >> x;
            seg.update(i, x);
        }
        else if (what == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r).even << '\n';
        }
        else if (what == 3) {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r).odd << '\n';
        }
    }
}