#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    int dp[10001]{0};
    dp[0] = 1;
    for(int i=1; i<=10000; i++) {
        dp[i] += dp[i-1];
    }
    for(int i=2; i<=10000; i++) {
        dp[i] += dp[i-2];
    }
    for(int i=3; i<=10000; i++) {
        dp[i] += dp[i-3];
    }
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}