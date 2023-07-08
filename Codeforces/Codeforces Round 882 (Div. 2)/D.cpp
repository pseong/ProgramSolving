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
	//////////////////// EDIT TYPE
	typedef struct {
		ll sum;
	} _T;
	typedef struct {
		ll a;
	} _L;
    _T op(_T a, _T b) {
    	return { a.sum + b.sum };
	}
    ////////////////////
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T t;
	Lazyseg() {}
	Lazyseg(int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, { 0 });
		lazy.assign(4*n+10, { 0 });
	}
	Lazyseg(const vector<ll>& A, int n, _T t) : n(n), t(t) {
		S.assign(4*n+10, { 0 });
		lazy.assign(4*n+10, { 0 });
		_init(A, 1, 1, n);
	}
	void init(int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, {0});
		lazy.assign(4*n+10, {0});
	}
	void init(const vector<ll>& A, int n, _T t) {
		this->n = n;
		this->t = t;
		S.assign(4*n+10, { 0 });
		lazy.assign(4*n+10, { 0 });
		_init(A, 1, 1, n);
	}
	_T _init(const vector<ll>& A, int node, int s, int e) {
		if (s == e) {
        	//////////////////// EDIT HERE
			S[node].sum = A[s];
        	////////////////////
			return S[node];
		}
		int mid = (s+e)/2;
		return S[node] = op(_init(A, node*2, s, mid), _init(A, node*2+1, mid+1, e));
	}
	void propagate(int node, int s, int e) {
		if (lazy[node].a == 0) return;
        //////////////////// EDIT HERE
        S[node].sum += ((ll)e-s+1)*lazy[node].a;
        if (s!=e) {
            lazy[node*2].a += lazy[node].a;
            lazy[node*2+1].a += lazy[node].a;
        }
		lazy[node].a = 0;
        ////////////////////
	}
	_T query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
		if (e < l || r < s) return t;
		if (l <= s && e <= r) return S[node];
		int mid = (s+e)/2;
		return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
	}
	_T query(int l, int r) {
        if (l > r) return { 0 };
		return query(1, 1, n, l, r);
	}
	void update_range(int node, int s, int e, int l, int r, _L x) {
        propagate(node, s, e);
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			//////////////////// EDIT HERE
			lazy[node].a += x.a;
            ////////////////////
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
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q;
    string s;
    cin >> n >> m >> q >> s;
    set<int> st;
    for (int i=1; i<=n+1; i++) st.insert(i);
    vector<int> num(n + 1);
    int now = 0;
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        while (true) {
            int x = *st.lower_bound(l);
            if (x > r) break;
            num[x] = ++now;
            st.erase(x);
        }
    }
    vector<ll> v(now + 1);
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        v[num[i]] = s[i-1] - '0';
        if (s[i-1] == '1') cnt++;
    }
    Lazyseg seg(v, now + 1, { 0 });
    while (q--) {
        int x;
        cin >> x;
        if (s[x-1] == '1') cnt--;
        else cnt++;
        s[x-1] ^= '0' ^ '1';
        x = num[x];
        if (x != 0) {
            int y = seg.query(x, x).sum;
            if (y == 0) seg.update_range(x, x, { 1 });
            else seg.update_range(x, x, { -1 });
        }
        int y = min(cnt, now);
        cout << y - seg.query(1, y).sum << '\n';
    }
}