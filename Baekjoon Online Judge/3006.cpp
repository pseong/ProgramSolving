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
		long long sum;
	} _T;
	typedef long long _L;
    //
    _T(*op)(_T, _T);
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T t;
	Lazyseg(_T(*op)(_T, _T), int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, {0});
		lazy.resize(4*n+10, {0});
	}
	Lazyseg(_T(*op)(_T, _T), const vector<long long>& A, int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, {0});
		lazy.resize(4*n+10, {0});
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
	void propagate(int node, int s, int e) {
		if (lazy[node] == 0) return;
        // EDIT HERE
        S[node].sum += ((long long)e-s+1)*lazy[node];
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

Lazyseg::_T op(Lazyseg::_T a, Lazyseg::_T b) {
    return { a.sum + b.sum };
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n + 1), idx(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        idx[v[i]] = i;
    }
    vector<ll> tmp(n + 1);
    for (int i=1; i<=n; i++) {
        tmp[i] = 1;
    }
    Lazyseg seg(op, tmp, n, { 0 });
    for (int i=1; i<=n; i++) {
        int I;
        if (i % 2 == 1) I = (i + 1) / 2;
        else I = n + 1 - i / 2;

        int now = idx[I];
        if (i % 2 == 1) {
            int go = (i + 1) / 2;
            cout << seg.query(1, now - 1).sum << '\n';
            seg.update_range(now, now, -1);
        }
        else {
            int go = n + 1 - i / 2;
            cout << seg.query(now + 1, n).sum << '\n';
            seg.update_range(now, now, -1);
        }
    }
}