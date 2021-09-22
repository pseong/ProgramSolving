#include <iostream>
#include <cstring>

using namespace std;

unsigned int an[510]{0};
unsigned int bn[510]{0};
unsigned int dp[510][510]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
        cin >> bn[i];
    }
    for(int i=1; i<=n; i++) {
        dp[i][i] = 0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i+1; j++) {
            for(int k=1; k<=i; k++) {
                dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][j+k-1]+dp[j+k][j+i-1]+an[j]*bn[j+k-1]*bn[j+i-1]);
            }
        }
    }
    cout << dp[1][n];
}