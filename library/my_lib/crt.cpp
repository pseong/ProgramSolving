#include <bits/stdc++.h>
using namespace std;

// input inverse a by b
// ouput a*s + b*t = r1
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

// input {{a1, m1}, {a2, m2}} : x = a1 (mod m1), y = a2 (mod m2)
// output {ans, lcm}
pair<ll, ll> crt(vector<pair<ll, ll>> v) {
    int n = v.size();
    auto [a1, m1] = v[0];
    a1 %= m1;
    for (int i=1; i<n; i++) {
        auto [a2, m2] = v[i];
        ll g = __gcd(m1, m2);
        if (a1%g != a2%g) return {-1, -1};
        auto [s, t, e] = xgcd(m1/g, m2/g);
        i128 mod = (i128)m1 / g * m2;
        a1 = ((i128)a1 * (m2/g) % mod) * t % mod + ((i128)a2 * (m1/g) % mod) * s % mod;
        a1 = (a1 + mod) % mod;
        m1 = mod;
    }
    return {a1, m1};
}