#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int an[101]{0};
    
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }

    long long dp[101][21]{0};
    dp[1][an[1]] = 1;
    for(int i=2; i<=n-1; i++) {
        for(int j=0; j<=20; j++) {
            if(j-an[i]>=0) dp[i][j] += dp[i-1][j-an[i]];
            if(j+an[i]<=20) dp[i][j] += dp[i-1][j+an[i]];
        }
    }
    cout << dp[n-1][an[n]];
}