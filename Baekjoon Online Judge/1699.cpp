#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    int dp[100010];
    fill(dp, dp + 100010, 100010);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i ++) {
        if(i == 128) {
            int breakk = 1;
            breakk += 3;
        }
        for(int j = 1; (i - j * j) >= 0; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[n];
}