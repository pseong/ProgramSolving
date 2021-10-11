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
ll an[N+1];
pll st[4*N];
int n;

pll init(int i, int l, int r) {
    if (l==r) {
        st[i].first = an[l];
        st[i].second = l;
        return st[i];
    }
    int m=l+r>>1;
    pll ret[2];
    ret[0] = init(i*2, l, m);
    ret[1] = init(i*2+1, m+1, r);
    sort(ret, ret+2);
    return st[i] = ret[0];
}

pll query(int i, int l, int r, int s, int e) {
    if (e<l || r<s) return {2000000000, -1};
    if (s<=l && r<=e) return st[i];
    int m=l+r>>1;
    pll ret[2];
    ret[0] = query(i*2, l, m, s, e);
    ret[1] = query(i*2+1, m+1, r, s, e);
    sort(ret, ret+2);
    return ret[0];
}

ll go(int l, int r) {
    if(l>r) return 0;
    int m=query(1, 1, n, l, r).second;
    ll res=an[m]*(r-l+1);
    res = max(res, go(l, m-1));
    res = max(res, go(m+1, r));
    return res;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(true) {
        cin >> n;
        if(n==0) break;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        init(1, 1, n);

        cout << go(1, n) << '\n';
    }
}