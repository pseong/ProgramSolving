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
 
ll day(ll a, ll b, ll v) {
    if (v <= a) return 1;
    return (v - b - 1) / (a - b) + 1;
}
 
void solve(int CASE) {
    int q;
    cin >> q;
    ll lo = 1;
    ll hi = 1e18;
    while (q--) {
        int what;
        cin >> what;
        if (what == 1) {
            ll a, b, n;
            cin >> a >> b >> n;
            ll l, h;
            if (n != 1) {
                ll now = (a - b) * (n - 1);
                l = now + b + 1;
                h = now + a;
            }
            else if (n == 1) {
                l = 1;
                h = a;
            }

            if (hi < l || h < lo) cout << 0 << ' ';
            else {
                lo = max(lo, l);
                hi = min(hi, h);
                cout << 1 << ' ';
            }
        }
        else if (what == 2) {
            ll a, b;
            cin >> a >> b;
            if (day(a, b, lo) != day(a, b, hi)) cout << -1 << ' ';
            else cout << day(a, b, lo) << ' ';
        }
    }
    cout << '\n';
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