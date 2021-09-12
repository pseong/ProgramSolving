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

    int dp[1001][4]{ 0 };
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];
    dp[1][3] = house[1][3];

    for(int i = 2; i <= n; i++) {
        dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + house[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + house[i][2];
        dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + house[i][3];
    }

    cout << min(min(dp[n][1], dp[n][2]), dp[n][3]);
}