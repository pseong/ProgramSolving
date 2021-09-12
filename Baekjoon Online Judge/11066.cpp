#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        int an[501]{0};
        int sum[501]{0};
        for(int i=1; i<=k; i++) {
            cin >> an[i];
            sum[i] = sum[i-1] + an[i];
        }
        int dp[501][501]{0};
        for(int i=1; i<=k-1; i++) {
            dp[i][i+1] = an[i]+an[i+1];
        }
        for(int d=2; d<k; d++) {
            for(int i=1; i<=k-d; i++) {
                int j=i+d;
                for(int n=i; n<=j-1; n++) {
                    if(!dp[i][j]) dp[i][j] = dp[i][n]+dp[n+1][j]+sum[j]-sum[i-1];
                    else dp[i][j] = min(dp[i][j], dp[i][n]+dp[n+1][j]+sum[j]-sum[i-1]);
                }
            }
        }
        cout << dp[1][k] << '\n';
    }
}