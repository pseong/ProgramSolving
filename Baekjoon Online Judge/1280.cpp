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
		long long sum, cnt;
	} _T;
    //
    _T(*op)(_T, _T);
	int n;
	vector<_T> S;
	Lazyseg(_T(*op)(_T, _T), int n) : op(op), n(n) {
		S.assign(4*n+10, {0, 0});
	}
	_T query(int node, int s, int e, int l, int r) {
		if (e < l || r < s) return {0, 0};
		if (l <= s && e <= r) return S[node];
		int mid = (s+e)/2;
		return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
	}
	_T query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	void update(int node, int s, int e, int p, ll x) {
		if (e < p || p < s) return;
		if (e == s) {
            S[node].cnt += x;
            S[node].sum += e*x;
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

const ll mod =  1000000007;

Lazyseg::_T op(Lazyseg::_T a, Lazyseg::_T b) {
    return { a.sum + b.sum, a.cnt + b.cnt };
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Lazyseg seg(op, 202020);
    ll ans = 1;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        a++;
        auto left = seg.query(1, a-1);
        auto right = seg.query(a+1, 202020);
        if (i != 0) ans *= (a * left.cnt - left.sum + right.sum - a * right.cnt) % mod;
        ans %= mod;
        seg.update(a, 1);
    }
    cout << ans << '\n';
}