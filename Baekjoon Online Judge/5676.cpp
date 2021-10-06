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
    return st[i] = init(i*2, l, m)*init(i*2+1, m+1, r)%1000000007;
}

ll update(int i, int l, int r, int p, ll x) {
    if (p<l || p>r) return st[i];
    if (l==r) return st[i] = x;
    int m=l+r>>1;
    return st[i] = update(i*2, l, m, p, x)*update(i*2+1, m+1, r, p, x)%1000000007;
}

ll query(int i, int l, int r, int s, int e) {
    if(e<l || r<s) return 1;
    if(s<=l && r<=e) return st[i];
    int m=l+r>>1;
    return query(i*2, l, m, s, e)*query(i*2+1, m+1, r, s, e)%1000000007;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    while(cin >> n) {
        cin >> k;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        init(1, 1, n);

        for(int i=0; i<k; i++) {
            char a;
            ll b, c;
            cin >> a >> b >> c;
            if(a=='C') {
                update(1, 1, n, b, c);
            } else {
                ll q=query(1, 1, n, b, c);
                char ans;
                if(q>0) ans = '+';
                else if(q<0) ans = '-';
                else ans = '0';
                cout << ans;
            }
        }
        cout << '\n';
    }
}