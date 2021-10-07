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
ll st[4*N];
ll lz[4*N];

ll init(int i, int l, int r) {
    if (l==r) return st[i] = an[l];
    int m=l+r>>1;
    return st[i] = init(i*2, l, m)+init(i*2+1, m+1, r);
}

void propagation(int i, int l, int r) {
    if (lz[i]) {
        st[i] += (r-l+1)*lz[i];
        if (l != r) {
            lz[i*2] += lz[i];
            lz[i*2+1] += lz[i];
        }
        lz[i] = 0;
    }
}

ll update(int i, int l, int r, int s, int e, long long x) {
    propagation(i, l, r);
    if (e<l || r<s) return st[i];
    if (s<=l && r<=e) {
        lz[i] += x;
        propagation(i, l, r);
        return st[i];
    }
    int m=l+r>>1;
    return st[i] = update(i*2, l, m, s, e, x)+update(i*2+1, m+1, r, s, e, x);
}

ll query(int i, int l, int r, int s, int e) {
    propagation(i, l, r);
    if (e<l || r<s) return 0;
    if (s<=l && r<=e) return st[i];
    int m=l+r>>1;
    return query(i*2, l, m, s, e)+query(i*2+1, m+1, r, s, e);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll ans=0;
    for(int i=1; i<=n; i++) {
        ll a, b;
        cin >> a >> b;
        ll fi=query(1, 1, 100000, a, a);
        ll se=query(1, 1, 100000, b, b);
        if(fi) update(1, 1, 100000, a, a, -fi);
        if(se) update(1, 1, 100000, b, b, -se);
        cout << fi+se << '\n';
        update(1, 1, 100000, a+1, b-1, 1);
    }
}