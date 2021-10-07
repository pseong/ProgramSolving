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
int diff[N+1];
ll st[4*N];
ll st2[4*N];

ll gcd(ll a, ll b) {
    return __gcd(abs(a), abs(b));
}

void init(int i, int l, int r) {
    if(l==r) {
        st[i] = diff[l];
        st2[i] = diff[l];
        return;
    }
    int m=l+r>>1;
    init(i*2, l, m);
    init(i*2+1, m+1, r);
    st[i] = st[i*2] + st[i*2+1];
    st2[i] = gcd(st2[i*2], st2[i*2+1]);
}

void update(int i, int l, int r, int p, ll x) {
    if (p<l || r<p) return;
    if (l==r) {
        st[i] += x;
        st2[i] += x;
        return;
    }
    int m=l+r>>1;
    update(i*2, l, m, p, x);
    update(i*2+1, m+1, r, p, x);
    st[i] = st[i*2] + st[i*2+1];
    st2[i] = gcd(st2[i*2], st2[i*2+1]);
}

ll query1(int i, int l, int r, int s, int e) {
    if (e<l || r<s) return 0;
    if (s<=l && r<=e) return st[i];
    int m=l+r>>1;
    return query1(i*2, l, m, s, e)+query1(i*2+1, m+1, r, s, e);
}

ll query2(int i, int l, int r, int s, int e) {
    if (e<l || r<s) return 0;
    if (s<=l && r<=e) return st2[i];
    int m=l+r>>1;
    return gcd(query2(i*2, l, m, s, e), query2(i*2+1, m+1, r, s, e));
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
        diff[i] = an[i]-an[i-1];
    }
    init(1, 1, n);

    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        ll t, a, b;
        cin >> t >> a >> b;
        if(t>0) {
            update(1, 1, n, a, t);
            update(1, 1, n, b+1, -t);
        } else {
            cout << gcd(query1(1, 1, n, 1, a), query2(1, 1, n, a+1, b)) << '\n'; 
        }
    }
}