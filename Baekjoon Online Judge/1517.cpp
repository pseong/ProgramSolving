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

pii an[1000010];
ll st[4000010]{0};

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

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        an[i] = {a, i};
    }
    sort(an+1, an+n+1);

    ll ans=0;
    for(int i=1; i<=n; i++) {
        int idx=an[i].second;
        ans += query(1, 1, n, idx, n);
        update(1, 1, n, idx, 1);
    }
    cout << ans;
}