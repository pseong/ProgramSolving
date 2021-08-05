#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    int house[1001][4]{ 0 };
    for(int i = 1; i <= n; i++) {
        cin >> house[i][1];
        cin >> house[i][2];
        cin >> house[i][3];
    }

    int ans = 1000*1000;
    for(int k=1; k<=3; k++) {
        int dp[1001][4]{ 0 };
        for(int j=1; j<=3; j++) {
            if(j==k) {
                dp[1][j] = house[1][j];
            } else {
                dp[1][j] = 1000*1000+1;
            }
        }

        for(int i = 2; i <= n; i++) {
            dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + house[i][1];
            dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + house[i][2];
            dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + house[i][3];
        }

        if(k!=1) ans = min(ans, dp[n][1]);
        if(k!=2) ans = min(ans, dp[n][2]);
        if(k!=3) ans = min(ans, dp[n][3]);
    }
    cout << ans;
}