#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    int dp[100002]{ 0 };
    int dp2[100002]{ 0 };
    int a[100002]{ 0 };
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    
    dp[1] = a[1];
    int ans = dp[1];
    for(int i=2; i<=n; i++) {
        dp[i] = a[i];
        if(dp[i] < dp[i-1] + a[i]) {
            dp[i] = dp[i-1] + a[i];
        }
        if(ans < dp[i]) ans = dp[i];
    }

    dp2[n] = a[n];
    for(int i=n-1; i>=1; i--) {
        dp2[i] = a[i];
        if(dp2[i] < dp2[i+1] + a[i]) {
            dp2[i] = dp2[i+1] + a[i];
        }
        if(ans < dp2[i]) ans = dp2[i];
    }

    for(int i=2; i<=n-1; i++) {
        if(ans < dp[i-1] + dp2[i+1]) {
            ans = dp[i-1] + dp2[i+1];
        }
    }
    cout << ans;
}