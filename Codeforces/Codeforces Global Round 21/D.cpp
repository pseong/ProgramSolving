#include <bits/stdc++.h>
#define int long long
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

const int inf = 10000000000;
struct Lazyseg {
	// EDIT TYPE
	typedef struct {
		long long mn, mx, mn_idx, mx_idx;
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
			S[node].mn = A[s];
            S[node].mn_idx = s;
            S[node].mx = A[s];
            S[node].mx_idx = s;
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(init(A, node*2, s, mid), init(A, node*2+1, mid+1, e));
	}
	void propagate(int node, int s, int e) {
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
    Lazyseg::_T ret;
    if (a.mn < b.mn) {
        ret.mn = a.mn;
        ret.mn_idx = a.mn_idx;
    }
    else {
        ret.mn = b.mn;
        ret.mn_idx = b.mn_idx;
    }

    if (a.mx > b.mx) {
        ret.mx = a.mx;
        ret.mx_idx = a.mx_idx;
    }
    else {
        ret.mx = b.mx;
        ret.mx_idx = b.mx_idx;
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    Lazyseg seg(op, v, n, { inf, -inf, inf, inf });
    stack<int> st;
    vector<int> u(n+1), d(n+1);
    for (int i=1; i<=n; i++) {
        if (st.empty()) st.push(i);
        else if (v[st.top()] > v[i]) st.push(i);
        else {
            while (st.size() && v[st.top()] < v[i]) {
                u[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (st.size()) {
        u[st.top()] = n+1;
        st.pop();
    }
    for (int i=1; i<=n; i++) {
        if (st.empty()) st.push(i);
        else if (v[st.top()] < v[i]) st.push(i);
        else {
            while (st.size() && v[st.top()] > v[i]) {
                d[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (st.size()) {
        d[st.top()] = n+1;
        st.pop();
    }

    int go = 1;
    int cnt = 0;
    while (go != n) {
        if (v[go] < v[go+1]) {
            auto at = seg.query(go, d[go]-1);
            go = at.mx_idx;
            cnt++;
        }
        else {
            auto at = seg.query(go, u[go]-1);
            go = at.mn_idx;
            cnt++;
        }
    }
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}