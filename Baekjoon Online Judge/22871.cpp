#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, a[5010];

int calc(int m) {
    int dp[5010]{ 0 };
    dp[1] = 1;
    for (int i=1; i<=n; i++) {
        if (dp[i] == 0) continue;
        for (int j=i+1; j<=n; j++) {
            if ((ll)(j-i)*(1+abs(a[i]-a[j])) <= m) {
                dp[j] = 1;
            }
        }
        if (dp[n] == 1) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int lo = 0;
    int hi = 1000000;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cal = calc(mid);
        if (cal == 0) {
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid - 1;
        }
    }
    cout << ans;
    return 0;
}