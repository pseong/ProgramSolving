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

int an[1000010]{0};
ll st[4000000]{0};

ll init(int i, int l, int r) {
    if (l==r) return st[i] = an[l];
    int m=l+r>>1;
    return st[i] = init(i*2, l, m) + init(i*2+1, m+1, r);
}

ll update(int i, int l, int r, int p, ll x) {
    if (p<l || p>r) return st[i];
    if (l==r) return st[i] = x;
    int m=l+r>>1;
    return st[i] = update(i*2, l, m, p, x)+update(i*2+1, m+1, r, p, x);
}

ll query(int i, int l, int r, int s, int e) {
    if(e<l || r<s) return 0;
    if(s<=l && r<=e) return st[i];
    int m=l+r>>1;
    return query(i*2, l, m, s, e)+query(i*2+1, m+1, r, s, e);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    init(1, 1, n);

    for(int i=0; i<m+k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1) {
            update(1, 1, n, b, c);
        } else {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }
}