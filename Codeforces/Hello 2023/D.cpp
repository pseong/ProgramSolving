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
	typedef struct {
		ll mx, idx;
	} _T;
	typedef ll _L;
    _T(*op)(_T, _T);
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T t;
	void init(_T(*op)(_T, _T), const vector<ll>& A, int n, _T t) {
        this->op = op;
        this->n = n;
        this->t = t;
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, {0});
		init(A, 1, 1, n);
	}
	_T init(const vector<long long>& A, int node, int s, int e) {
		if (s == e) {
			S[node].mx = A[s];
            S[node].idx = s;
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
    if (a.mx < b.mx) return b;
    else return a;
}

Lazyseg seg;
multiset<ll> ms;
vector<ll> a, b;

bool chk(int l, int r, ll prev) {
    if (l > r) return true;
    auto at = seg.query(l, r);
    bool b = false;
    if (at.mx < min(prev, a[at.idx])) {
        auto it = ms.lower_bound(at.mx);
        if (it == ms.end() || *it != at.mx) return false;
        ms.erase(it);
        b = true;
    }
    ll x = prev;
    if (b) x = at.mx;
    if (chk(l, at.idx-1, x) && chk(at.idx+1, r, x)) return true;
    else return false;
}

void solve(int CASE) {
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    b.assign(n + 1, 0);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    seg.init(op, b, n, { 0 });
    int m;
    cin >> m;
    ms.clear();
    for (int i=0; i<m; i++) {
        ll x;
        cin >> x;
        ms.insert(x);
    }
    for (int i=1; i<=n; i++) {
        if (a[i] < b[i]) {
            no();
            return;
        }
    }
    if (chk(1, n, 1e18)) yes();
    else no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}