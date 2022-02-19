#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll s;

ll calc(ll a) {
    return a*(a+1)/2;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> s;

    ll lo = 1;
    ll hi = 100000;
    ll ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cal = calc(mid);
        if (cal <= s) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << ans;
}