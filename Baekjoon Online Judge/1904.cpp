#include <iostream>

using namespace std;

int dp[1000001]{0};
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }
    cout << dp[n];
}