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

struct Lazyseg{
    ll S[1000000*8 + 10];
    ll lazy[1000000*8+ 10];

    ll op(ll a, ll b) {
        return a + b;
    }

    void propagation(int n, int s, int e) {
        if (lazy[n] == 0) return;
        S[n] += (ll)(s - e + 1) * lazy[n];
        if (s != e) {
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }

    void update_range(int n, int s, int e, int l, int r, ll x) {
        propagation(n, s, e);
        if (e < l || r < s) return;
        if (l <= s && e <= r) {
            lazy[n] += x;
            propagation(n, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update_range(n*2, s, mid, l, r, x);
        update_range(n*2+1, mid+1, e, l, r, x);
        S[n] = op(S[n*2], S[n*2+1]);
    }

    ll query(int n, int s, int e, int l, int r) {
        propagation(n, s, e);
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) return S[n];
        int mid = (s + e) / 2;
        return op(query(n*2, s, mid, l, r), query(n*2+1, mid+1, e, l, r));
    }
} seg;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i=0; i<q; i++) {
        int what;
        cin >> what;
        if (what == 1) {
            int p, x;
            cin >> p >> x;
            seg.update_range(1, 1, n, p, p, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 1, n, l, r) << '\n';
        }
    }
}