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
		if (l <= s && e <= r) S[node].cnt += x;
        else {
            int mid = (s + e) / 2;
            update_range(node*2, s, mid, l, r, x);
            update_range(node*2+1, mid+1, e, l, r, x);
        }
        if (S[node].cnt) S[node].sum = e - s + 1;
		else if (s == e) S[node].sum = 0;
        else S[node] = op(S[node*2], S[node*2+1]);
	}
	void update_range(int l, int r, _L x) {
		update_range(1, 1, n, l, r, x);
	}
};

Lazyseg::_T op(Lazyseg::_T a, Lazyseg::_T b) {
    return { a.sum + b.sum };
}

struct Event{
    int s, e, op, x;

    bool operator<(Event& r) {
        return x < r.x;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Lazyseg seg(op, 30303, { 0 });
    int n;
    cin >> n;
    
    vector<Event> events;
    for (int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        events.push_back({b, d, 1, a});
        events.push_back({b, d, -1, c});
    }
    sort(events.begin(), events.end());

    ll ans = 0;
    int now = 0;
    for (auto [s, e, op, x] : events) {
        ans += (ll)(x - now) * seg.query(1, 30303).sum; 
        now = x;
        if (op == 1) {
            seg.update_range(s, e-1, 1);
        }
        else{
            seg.update_range(s, e-1, -1);
        }
    }

    cout << ans << '\n';
}