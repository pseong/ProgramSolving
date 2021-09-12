#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long dp[101]{0};
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = dp[i-1]+1;
        for(int j=1; j<=i-2; j++) {
            dp[i] = max(dp[i], dp[i-(j+2)]*(j+1));
        }
    }
    cout << dp[n];
}