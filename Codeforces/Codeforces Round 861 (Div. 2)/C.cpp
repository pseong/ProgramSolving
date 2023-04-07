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
 
int cal(ll x) {
    string s = to_string(x);
    return *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end());
}
 
void solve(int CASE) {
    ll l, r;
    cin >> l >> r;
    ll ans = 10;
    ll ans2 = -1;
    ll w = 0;
    while (true) {
        ll x = l;
        ll c = x % 10;
        for (int i=0; i<w; i++) {
            x *= 10;
            x += c;
        }
        if (x > r) break;
        if (ans > cal(x)) {
            ans = cal(x);
            ans2 = x;
        }
        string s = to_string(l);
        ll mn = min_element(s.rbegin(), s.rend()) - s.rbegin();
        ll mx = max_element(s.rbegin(), s.rend()) - s.rbegin();
        ll m = min(mn, mx);
        w += m;
        for (int i=0; i<m; i++) l /= 10;
        l++;
    }
    cout << ans2 << '\n';
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