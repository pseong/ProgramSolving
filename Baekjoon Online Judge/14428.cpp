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

const int N = 1000000;
int an[N+1];
pll st[4*N];
ll lz[4*N];

pll init(int i, int l, int r) {
    if (l==r) {
        return st[i] = {an[l], l};
    }
    int m=l+r>>1;

    pll ret[2];
    ret[0] = init(i*2, l, m);
    ret[1] = init(i*2+1, m+1, r);
    sort(ret, ret+2);
    return st[i] = ret[0];
}

void propagation(int i, int l, int r) {
    if (lz[i]) {
        st[i].first = lz[i];
        if (l != r) {
            lz[i*2] = lz[i];
            lz[i*2+1] = lz[i];
        }
        lz[i] = 0;
    }
}

pll update(int i, int l, int r, int s, int e, long long x) {
    propagation(i, l, r);
    if (e<l || r<s) return st[i];
    if (s<=l && r<=e) {
        lz[i] = x;
        propagation(i, l, r);
        return st[i];
    }
    int m=l+r>>1;
    pll ret[2];
    ret[0] = update(i*2, l, m, s, e, x);
    ret[1] = update(i*2+1, m+1, r, s, e, x);
    sort(ret, ret+2);
    return st[i] = ret[0];
}

pll query(int i, int l, int r, int s, int e) {
    propagation(i, l, r);
    if (e<l || r<s) return {2000000000,-1};
    if (s<=l && r<=e) return st[i];
    int m=l+r>>1;
    pll ret[2];
    ret[0] = query(i*2, l, m, s, e);
    ret[1] = query(i*2+1, m+1, r, s, e);
    sort(ret, ret+2);
    return ret[0];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    init(1, 1, n);
    
    cin >> m;
    for(int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1) update(1, 1, n, b, b, c);
        else cout << query(1, 1, n, b, c).second << '\n';
    }
}