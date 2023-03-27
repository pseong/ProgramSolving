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

struct DynamicMaxSubarraySum {
	typedef struct {
		ll lval, rval, val, all;
	} _T;
	int n;
	_T t = {(ll)-1e18, (ll)-1e18, (ll)-1e18, 0};
	vector<_T> S;
    _T op(_T left, _T right) {
        return {
            max(left.lval, left.all + right.lval),
            max(right.rval, left.rval + right.all),
            max({left.val, right.val, left.rval + right.lval}),
            left.all + right.all,
        };
    }
	DynamicMaxSubarraySum() {}
	DynamicMaxSubarraySum(int n) : n(n) {
		S.assign(4*n+10, {0});
	}
	DynamicMaxSubarraySum(const vector<ll>& A, int n) : n(n) {
		S.assign(4*n+10, {0});
		_init(A, 1, 1, n);
	}
	void init(int n) {
		this->n = n;
		S.assign(4*n+10, {0});
	}
	void init(const vector<ll>& A, int n) {
		this->n = n;
		S.assign(4*n+10, {0});
		_init(A, 1, 1, n);
	}
	_T _init(const vector<ll>& A, int node, int s, int e) {
		if (s == e) {
            S[node].lval = A[s];
            S[node].rval = A[s];
            S[node].val = A[s];
            S[node].all = A[s];
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(_init(A, node*2, s, mid), _init(A, node*2+1, mid+1, e));
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
	void update(int node, int s, int e, int p, ll x) {
		if (p < s || e < p) return;
		if (s == e) {
            S[node].all += x;
            S[node].lval += x;
            S[node].rval += x;
            S[node].val += x;
			return;
		}
		int mid = (s + e) / 2;
		update(node*2, s, mid, p, x);
		update(node*2+1, mid+1, e, p, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void update(int p, ll x) {
		update(1, 1, n, p, x);
	}
};

const ll inf = 1e18;

void solve(int CASE) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n + 1);
    if (x < 0) {
        k = n - k;
        x = -x;
    }
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] -= x;
    }
    for (int i=1; i<=k; i++) {
        v[i] += 2*x;
    }
    DynamicMaxSubarraySum seg(v, n);
    ll ans = 0;
    ans = max(ans, seg.query(1, n).val);
    if (k == 0) {
        cout << ans << '\n';
        return;
    }
    for (int i=k+1; i<=n; i++) {
        seg.update(i, 2*x);
        seg.update(i-k, -2*x);
        ans = max(ans, seg.query(1, n).val);
    }
    cout << ans << '\n';
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