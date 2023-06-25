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

const int inf = 1e9;

struct MinIndex {
	typedef struct {
		ll mx;
	} _T;
    _T op(_T a, _T b) {
    	return { max(a.mx, b.mx) };
	}
	int n;
	vector<_T> S;
	_T t;
	MinIndex() {}
	MinIndex(int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, { 0 });
	}
	MinIndex(const vector<ll>& A, int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, { 0 });
		_init(A, 1, 1, n);
	}
	void init(int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, { 0 });
	}
	void init(const vector<ll>& A, int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, { 0 });
		_init(A, 1, 1, n);
	}
	_T _init(const vector<ll>& A, int node, int s, int e) {
		if (s == e) {
			S[node].mx = A[s];
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(_init(A, node*2, s, mid), _init(A, node*2+1, mid+1, e));
	}
	ll query(int node, int s, int e, int l, int r, int c) {
		if (e < l || r < s) return t.mx;
		int mid = (s+e)/2;
        if (s == e) {
            if (S[node].mx >= c) return { s };
            else return t.mx;
        }
		if (l <= s && e <= r) {
            if (S[node*2].mx >= c) return query(node*2, s, mid, l, r, c);
            else if (S[node*2+1].mx >= c) return query(node*2+1, mid+1, e, l, r, c);
            else return t.mx;
        }
        return min(query(node*2, s, mid, l, r, c), query(node*2+1, mid+1, e, l, r, c));
	}
	ll query(int l, int r, int c) {
		return query(1, 1, n, l, r, c);
	}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n + 2), dp(n + 2), t(n + 2), pref(n + 2);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        dp[i] = min(dp[i-1] + 1, v[i]);
        pref[i] = pref[i-1] + dp[i];
    }
    vector<ll> s(n + 1);
    for (int i=1; i<=n; i++) {
        s[i] = max(1LL, i - v[i] + 1);
    }
    MinIndex seg(s, n, { n + 1 });
    for (int i=n; i>=1; i--) {
        ll l = max(1LL, i-v[i]+1);
        ll q = seg.query(i + 1, n, l);
        ll a = i - l + 1;
        ll b = q - l;
        t[i] = (b - a + 1)*(a + b)/2 + t[q];
    }
    int q;
    cin >> q;
    while (q--) {
        ll p, x;
        cin >> p >> x;
        ll d = min(dp[p-1]+1, x);
        ll l = max(1LL, p - d + 1);
        ll q = seg.query(p + 1, n, l);
        ll g = q - l;
        cout << pref[p-1] + (g - d + 1)*(d + g)/2 + t[q] << '\n';
    }
}