#include <bits/stdc++.h>
using namespace std;

pair<ll, ll> exgcd(ll a, ll b) {
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
    return {s, t};
}

ll inverse(ll A, ll B) {
    auto [s, t] = exgcd(A, B);
    if (s < 0) s += B;
    return s;
}

ll china(vector<pair<ll, ll>> vec) {
    i128 mod = 1;
    for (auto [a, md] : vec) mod *= md;
    ll x = 0;
    for (auto [a, md] : vec) {
        x += (mod/md * inverse(mod/md, md) % mod * a % mod) % mod;
        x %= mod;
    }
    return x;
}