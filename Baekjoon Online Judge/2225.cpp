#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int dp[201][201]{ 0 };
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++) {
        for(int j=0; j<=n; j++) {
            for(int l=0; l<=j; l++) {
                dp[i][j] += dp[i-1][j-l];
                dp[i][j] %= 1000000000; 
            }
        }
    }

    cout << dp[k][n];
}