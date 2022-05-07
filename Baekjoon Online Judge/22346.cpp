#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

map<pll, pll> prel;
map<pll, pll> prer;
map<pll, pll> prea;

ll length(ll n) {
    for (ll  z=(1LL<<59); z>=0; z>>=1) {
        if (n & z) {
            n |= (z-1);
            break;
        }
    }
    return n;
}

pll getl(ll n, ll s, ll e, ll k) {
    if (e < s) return {0, 0};
    if (n == 1) return {1, 0};
    ll len = length(n);
    if (e-s+1 == len && prel.find({n, k}) != prel.end()) return prel[{n, k}];
    ll m = (1+len)/2;
    if (e < m) return getl(n/2, s, e, k);
    else if (s > m) return getl(n/2, s-m, e-m, k);
    else {
        ll l, cnt;
        tie(l, cnt) = getl(n/2, s, m-1, k);
        assert(cnt <= k);
        if (l == m-s) {
            if (n%2 == 0 && cnt < k || n%2 == 1) {
                if (n%2 == 0) cnt += 1;
                ll r, c;
                tie(r, c) = getl(n/2, 1, e-m, k-cnt);
                l = l+1+r;
                cnt += c;
            }
        }
        if (e-s+1 == len) prel[{n, k}] = {l, cnt};
        return {l, cnt};
    }
}

pll getr(ll n, ll s, ll e, ll k) {
    if (e < s) return {0, 0};
    if (n == 1) return {1, 0};
    ll len = length(n);
    if (e-s+1 == len && prer.find({n, k}) != prer.end()) return prer[{n, k}];
    ll m = (1+len)/2;
    if (e < m) return getr(n/2, s, e, k);
    else if (s > m) return getr(n/2, s-m, e-m, k);
    else {
        ll r, cnt;
        tie(r, cnt) = getr(n/2, 1, e-m, k);
        assert(cnt <= k);
        if (r == e-m) {
            if (n%2 == 0 && cnt < k || n%2 == 1) {
                if (n%2 == 0) cnt += 1;
                ll l, c;
                tie(l, c) = getr(n/2, s, m-1, k-cnt);
                r = l+1+r;
                cnt += c;
            }
        }
        if (e-s+1 == len) prer[{n, k}] = {r, cnt};
        return {r, cnt};
    }
}


pll geta(ll n, ll s, ll e, ll k) {
    if (e < s) return {0, 0};
    if (n == 1) return {1, 0};
    ll len = length(n);
    if (e-s+1 == len && prea.find({n, k}) != prea.end()) return prea[{n, k}];
    ll m = (1+len)/2;
    if (e < m) return geta(n/2, s, e, k);
    else if (s > m) return geta(n/2, s-m, e-m, k);
    else {
        ll ans, ans_cnt = 0;
        ll l_a, l_acnt, l_r, l_rcnt, r_a, r_acnt, r_l, r_lcnt;
        tie(l_a, l_acnt) = geta(n/2, s, m-1, k);
        tie(r_a, r_acnt) = geta(n/2, 1, e-m, k);
        ans = l_a; ans_cnt = l_acnt;
        if (ans < r_a) {
            ans = r_a; ans_cnt = r_acnt;
        }
        
        for (ll c = 0; c <= k-abs(n%2-1); c++) {
            tie(l_r, l_rcnt) = getr(n/2, s, m-1, c);
            tie(r_l, r_lcnt) = getl(n/2, 1, e-m, k-c-abs(n%2-1));
            if (ans < l_r+1+r_l) {
                ans = l_r+1+r_l;
                ans_cnt = l_rcnt+r_lcnt+abs(n%2-1);
            }
        }

        if (len == e-s+1) prea[{n, k}] = {ans, ans_cnt};
        return {ans, ans_cnt};
    }
}

int main() {

    ll n, Q;
    cin >> n >> Q;
    
    for (int q=0; q<Q; q++) {
        ll i, j, k;
        cin >> i >> j >> k;

        cout << geta(n, i, j, k).first << '\n';
    }
}