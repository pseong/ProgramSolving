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
int an[N + 1];
ll st[4 * N];
ll st2[4 * N];
ll lz[4 * N];

ll init(int i, int l, int r) {
    if (l==r) return st[i] = an[l];
    int m=l+r>>1;
    return st[i] = max(init(i*2, l, m), init(i*2+1, m+1, r));
}

ll init2(int i, int l, int r) {
    if (l==r) return st2[i] = an[l];
    int m=l+r>>1;
    return st2[i] = min(init2(i*2, l, m), init2(i*2+1, m+1, r));
}
ll query(int i, int l, int r, int s, int e) {
    if (e<l || r<s) return 0;
    if (s<=l && r<=e) return st[i];
    int m=l+r>>1;
    return max(query(i*2, l, m, s, e), query(i*2+1, m+1, r, s, e));
}

ll query2(int i, int l, int r, int s, int e) {
    if (e<l || r<s) return 1000000000;
    if (s<=l && r<=e) return st2[i];
    int m=l+r>>1;
    return min(query2(i*2, l, m, s, e), query2(i*2+1, m+1, r, s, e));
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    init(1, 1, n);
    init2(1, 1, n);

    for(int i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        cout << query2(1, 1, n, a, b) << ' ' << query(1, 1, n, a, b) << '\n';
    }
}