#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll n, k;

ll calc(ll mid) {
    return (mid + 1) * (n - mid + 1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    ll lo = 0;
    ll hi = n / 2;
    ll ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cal = calc(mid);
        if (cal <= k) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    if (calc(ans) == k) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}