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
		long long mx, mn, mxi, mni;
	} _T;
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
			S[node].mn = A[s];
			S[node].mxi = s;
			S[node].mni = s;
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
};

Lazyseg::_T op(Lazyseg::_T a, Lazyseg::_T b) {
    return { max(a.mx, b.mx), min(a.mn, b.mn), ((a.mx > b.mx) ? a.mxi : b.mxi), ((a.mn < b.mn) ? a.mni : b.mni) };
}

const ll inf = 1e9;
void solve(int CASE) {
    int n;
    cin >> n;
    vector<ll> v(n + 1), idx(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        idx[v[i]] = i;
    }
    Lazyseg seg(op, v, n, { -inf, inf, -1, -1 });
    int l = 1;
    int r = n;
    while (l < r) {
        auto at = seg.query(1, 1, n, l, r);
        if (at.mni == l || at.mxi == l) l++;
        else if (at.mni == r || at.mxi == r) r--;
        else {
            cout << l << ' ' << r << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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