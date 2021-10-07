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
ll st[4*N];
ll lz[4*N];

void propagation(int i, int l, int r) {
    if (lz[i]) {
        if(lz[i]%2==1) st[i] = (r-l+1)-st[i];
        if (l != r) {
            lz[i*2] += lz[i];
            lz[i*2+1] += lz[i];
        }
        lz[i] = 0;
    }
}

ll update(int i, int l, int r, int s, int e) {
    propagation(i, l, r);
    if (e<l || r<s) return st[i];
    if (s<=l && r<=e) {
        lz[i] += 1;
        propagation(i, l, r);
        return st[i];
    }
    int m=l+r>>1;
    return st[i] = update(i*2, l, m, s, e)+update(i*2+1, m+1, r, s, e);
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

    ll n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==0) {
            update(1, 1, n, b, c);
        } else {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }
}