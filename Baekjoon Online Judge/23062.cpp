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

tuple<ll, ll, ll> xgcd(ll a, ll b) {
    ll s, t;
    ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
    ll r, q;
    while (r2) {
        q = r1 / r2;
        r = r1 % r2;
        r1 = r2, r2 = r;
        s = s1 - q * s2;
        s1 = s2, s2 = s;
        t = t1 - q * t2;
        t1 = t2, t2 = t;
    }
    s = s1;
    t = t1;
    if (s <= 0) {
        s += b;
        t -= a;
    }
    return {s, t, r1};
}

pair<ll, ll> crt(vector<pair<ll, ll>> v) {
    int n = v.size();
    auto [a1, m1] = v[0];
    a1 %= m1;
    for (int i=1; i<n; i++) {
        auto [a2, m2] = v[i];
        ll g = __gcd(m1, m2);
        if (a1%g != a2%g) return {-1, -1};
        auto [s, t, e] = xgcd(m1/g, m2/g);
        i128 mod = (i128)m1 / g * m2; // set mod to lcm(m1, m2)
        a1 = ((i128)a1 * (m2/g) % mod) * t % mod + ((i128)a2 * (m1/g) % mod) * s % mod;
        a1 = (a1 + mod) % mod;
        m1 = mod;
    }
    return {a1, m1};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, x, y, z;
        cin >> a >> b >> c >> x >> y >> z;
        auto ans = crt({{x, a}, {y, b}, {z, c}});
        cout << ans.first << '\n';
    }
}