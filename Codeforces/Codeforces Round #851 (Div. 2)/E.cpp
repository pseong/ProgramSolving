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

const ll inf = 1e18;

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
		S.assign(4*n+10, { -inf });
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
	void update_range(int node, int s, int e, int l, int r, _L x) {
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
            S[node].mx = x;
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
    return { max(a.mx, b.mx) };
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> v(n + 1), pref(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }
    vector<ll> comp = pref;
    sort(comp.begin()+1, comp.end());
    comp.erase(unique(comp.begin() + 1, comp.end()), comp.end());
    map<ll, ll> mp;
    for (int i=1; i<(int)comp.size(); i++) {
        mp[comp[i]] = i;
    }
    vector<ll> dp(n + 1);
    Lazyseg seg(op, (int)comp.size(), { -inf });
    for (int i=1; i<=n; i++) {
        dp[i] = dp[i-1];
        if (pref[i] >= 0) dp[i] = max(dp[i], (ll)i);
        ll mx = seg.query(mp[pref[i]], mp[pref[i]]).mx;
        auto at = seg.query(1, mp[pref[i]]);
        dp[i] = max(dp[i], at.mx + i);
        seg.update_range(mp[pref[i]], mp[pref[i]], dp[i] - i);
    }
    cout << dp[n] << '\n';
}