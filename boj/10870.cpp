#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int dp[21]{0};
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=20; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }
    int n;
    cin >> n;
    cout << dp[n];
}