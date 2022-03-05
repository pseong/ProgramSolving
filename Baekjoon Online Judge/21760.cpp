#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll n, m, k, d;

ll calc(ll mid) {
    ll a = n*m*(m-1)*mid*k/2;
    ll b = n*(n-1)*m*m*mid/2;
    return a + b;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> n >> m >> k >> d;

        ll lo = 1;
        ll hi = 1000000000ll;
        ll ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll cal = calc(mid);
            if (cal <= d) {
                ans = cal;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        cout << ans << '\n';
    }
}