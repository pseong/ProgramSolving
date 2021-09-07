#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int an[101]{0};
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }

    int dp[10001]{0};
    dp[0] = 1;
    for(int j=1; j<=n; j++) {
        for(int i=1; i<=k; i++) {
            if(i-an[j]>=0) dp[i] += dp[i-an[j]];
        }
    }
    cout << dp[k];
}