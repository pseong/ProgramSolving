#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int dp[100001][4]{ 0 };
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 4; i <= n; i++) {
            dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % 1000000009;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % 1000000009;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % 1000000009;
        }

        cout << ((dp[n][1] + dp[n][2]) % 1000000009 + dp[n][3]) % 1000000009 << '\n';
    }
}