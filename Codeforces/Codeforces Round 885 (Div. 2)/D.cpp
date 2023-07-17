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
 
ll s, k, v[4];
 
ll get(int idx) {
    if (idx == 0) return s;
    idx--;
    ll cnt = idx / 4;
    return v[idx % 4] + 20 * cnt;
}
 
void solve(int CASE) {
    cin >> s >> k;
    v[0] = s + s % 10;
    v[1] = v[0] + v[0] % 10;
    v[2] = v[1] + v[1] % 10;
    v[3] = v[2] + v[2] % 10;
    if (s%10 == 0) {
        cout << s * k << '\n';
        return;
    }
    if (s%10 == 5) {
        cout << max(s * k, (s + 5) * (k - 1)) << '\n';
        return;
    }
    ll ans = s * k;
    for (ll mod=0; mod<4; mod++) {
        ll lo = 1;
        ll hi = k;
        while (lo + 100 <= hi) {
            ll l = (hi + 2*lo) / 3;
            ll r = (2*hi + lo) / 3;
            while (l%4 != mod) l--;
            while (r%4 != mod) r--;
            ll L = get(l) * (k - l);
            ll R = get(r) * (k - r);
            if (L < R) lo = l;
            else hi = r;
        }
        for (ll i=lo; i<=hi; i++) {
            ans = max(ans, get(i) * (k - i));
        }
    }
    cout << ans << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
#if TEST
    freopen("/Users/macrent/ProgramSolving/input.txt", "r", stdin);
#endif
 
    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}