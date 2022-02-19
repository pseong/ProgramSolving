#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll n;

ll calc(ll a) {
    return a*a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    ll lo = 0;
    ll hi = 3037000500;
    ll ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cal = calc(mid);
        if (cal >= n) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans;
}