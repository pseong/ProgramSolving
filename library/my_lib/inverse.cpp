#include <bits/stdc++.h>
using namespace std;
using ll=long long;

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

ll inverse(ll A, ll B) {
    auto [s, t, e] = xgcd(A, B);
    if (s < 0) s += B;
    return s;
}