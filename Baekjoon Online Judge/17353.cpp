#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <list>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

const ll N = 1000000;
ll an[N+1];
ll st[4*N];
pll lz[4*N];

ll init(ll i, ll l, ll r) {
    if (l==r) return st[i] = an[l];
    ll m=(l+r)>>1;
    return st[i] = init(i*2, l, m)+init(i*2+1, m+1, r);
}

void propagation(ll i, ll l, ll r) {
    if (lz[i].first) {
        ll x=lz[i].first;
        ll d=lz[i].second;
        ll k=r-l+1;
        st[i] += k*(2*x+(k-1)*d)/2;
        if (l != r) {
            ll m=(l+r)>>1;
            ll gap=m-l+1;
            lz[i*2].first += lz[i].first;
            lz[i*2].second += lz[i].second;
            lz[i*2+1].first += lz[i].first+gap*lz[i].second;
            lz[i*2+1].second += lz[i].second;
        }
        lz[i].first = 0;
        lz[i].second = 0;
    }
}

ll update(ll i, ll l, ll r, ll s, ll e) {
    propagation(i, l, r);
    if (e<l || r<s) return st[i];
    if (s<=l && r<=e) {
        lz[i].first += 1+l-s;
        lz[i].second++;
        propagation(i, l, r);
        return st[i];
    }
    ll m=(l+r)>>1;
    return st[i] = update(i*2, l, m, s, e)+update(i*2+1, m+1, r, s, e);
}

ll query(ll i, ll l, ll r, ll s, ll e) {
    propagation(i, l, r);
    if (e<l || r<s) return 0;
    if (s<=l && r<=e) return st[i];
    ll m=(l+r)>>1;
    return query(i*2, l, m, s, e)+query(i*2+1, m+1, r, s, e);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++) {
        cin >> an[i];
    }
    init(1, 1, n);

    ll q;
    cin >> q;
    for(ll i=0; i<q; i++) {
        ll a, b;
        cin >> a >> b;
        if(a==1) {
            ll c;
            cin >> c;
            update(1, 1, n, b, c);
        } else {
            cout << query(1, 1, n, b, b) << '\n';
        }
    }
}