#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    long long dp[5001]{0}; // 0 = {, 1 = }
    dp[0] = 1;
    for(int i=1; i<=5000; i++) {
        for(int j=2; i-j>=0; j+=2) {
            dp[i] = (dp[i] + dp[i-j]*dp[j-2]) % 1000000007;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        cout << dp[a] << '\n';
    }
}