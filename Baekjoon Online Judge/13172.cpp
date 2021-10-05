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

ll pow(int a, int r) {
    if(r==0) return 1;
    if(r==1) return a;
    if(r%2==1) {
        return a*pow(a, r-1) % 1000000007;
    } else {
        ll res=pow(a, r/2);
        res = res*res % 1000000007;
        return res;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int m;
    cin >> m;
    int n[10010]{0};
    int s[10010]{0};
    for(int i=1; i<=m; i++) {
        cin >> n[i] >> s[i];
    }
    ll ans=0;
    for(int i=1; i<=m; i++) {
        ans += s[i]*pow(n[i], 1000000007-2) % 1000000007;
        ans %= 1000000007;
    }
    cout << ans;
}