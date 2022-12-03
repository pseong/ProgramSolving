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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<ll> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=2; i<=n; i++) {
        if (v[i] % v[i-1] == 0) continue;
        else v[i] = (v[i] / v[i-1] + 1) * v[i-1];
    }
    while (q--) {
        ll t, l, r;
        cin >> t >> l >> r;
        ll lo = 1;
        ll hi = n;
        ll s = 0;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll d = t / v[mid] * v[mid] - mid;
            if (d <= r) {
                if (d >= l) s = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        lo = 1;
        hi = n;
        ll e = 0;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll d = t / v[mid] * v[mid] - mid;
            if (d >= l) {
                if (d <= r) e = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        ll res = 0;
        if (s != 0 && e != 0 && s <= e) {
            res = e - s + 1;
        }
        if (l <= t && t <= r) res++;
        cout << res << '\n';
    }
}