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

ll pow(ll a, ll r) {
    ll res=1;
    for(ll i=0; i<r; i++) {
        res *= a;
        res %= 1000000007;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;

        ll ans=0;
        for(ll l=30; l>=0; l--) {
            if(k>=(1<<l)) {
                k -= (1<<l);
                ans += pow(n, l);
                ans %= 1000000007;
            }
        }
        cout << ans << '\n';
    }
}