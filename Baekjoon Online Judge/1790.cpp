#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll calc(int n) {
    ll ans = 0;
    for (ll start=1, len=1; start<=n; start*=10, len++) {
        ll end = start*10-1;
        if (end > n) {
            end = n;
        }
        ans += (end - start + 1) * len;
    }
    return ans;
}

int n, k;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    if (calc(n) < k) {
        cout << -1;
        return 0;
    }
    int lo = 1;
    int hi = n;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        ll cal = calc(mid);
        if (cal < k) {
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid-1;
        }
    }
    ll cal = calc(ans);
    string s = to_string(ans);
    cout << s[s.length()-(cal-k)-1];
    return 0;
}