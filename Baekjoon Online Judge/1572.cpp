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
    ll seg[404040];
    ll lazy[404040];

    ll op(ll a, ll b) {
        return a + b;
    }

    void propagation(int n, int s, int e) {
        if (lazy[n] == 0) return;
        seg[n] += (ll)(e - s + 1) * lazy[n];
        if (s != e) {
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }

    void update(int n, int s, int e, int l, int r, ll x) {
        propagation(n, s, e);
        if (e < l || r < s) return;
        if (l <= s && e <= r) {
            lazy[n] += x;
            propagation(n, s, e);
            return;
        }
        int m = (s + e) / 2;
        update(n*2, s, m, l, r, x);
        update(n*2+1, m+1, e, l, r, x);
        seg[n] = op(seg[n*2], seg[n*2+1]);
    }

    ll query(int n, int s, int e, int l, int r, int k) {
        propagation(n, s, e);
        if (s == e) return s;
        int m = (s + e) / 2;
        if (seg[n*2] >= k) return query(n*2, s, m, l, r, k);
        else return query(n*2+1, m+1, e, l, r, k-seg[n*2]);
    }
} seg;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[i]++;
    }
    for (int i=1; i<k; i++) {
        seg.update(1, 1, 100000, v[i], v[i], 1);
    }

    ll ans = 0;
    for (int i=k; i<=n; i++) {
        seg.update(1, 1, 100000, v[i], v[i], 1);
        ans += seg.query(1, 1, 100000, 1, 100000, ((k + 1) / 2)) - 1;
        seg.update(1, 1, 100000, v[i-k+1], v[i-k+1], -1);
    }
    cout << ans << '\n';
}