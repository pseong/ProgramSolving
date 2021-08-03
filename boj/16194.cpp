#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    int card[1001]{ 0 };
    for(int i = 1; i <= n; i++) {
        cin >> card[i];
    }

    int dp[1001]{ 0 };
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + card[1];
        for(int j = 2; j <= n; j++) {
            if(i-j < 0) continue;
            dp[i] = min(dp[i], dp[i-j] + card[j]);
        }
    }

    cout << dp[n];
}