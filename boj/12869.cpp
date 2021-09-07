#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int an[4]{0};
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }

    int dp[71][71][71]{0};
    for(int i=70; i>=0; i--) {
        for(int j=70; j>=0; j--) {
            for(int k=70; k>=0; k--) {
                if(i>=an[1]&&j>=an[2]&&k>=an[3]) continue;
                dp[i][j][k] = 100;
            }
        }
    }
    for(int i=60; i>=0; i--) {
        for(int j=60; j>=0; j--) {
            for(int k=60; k>=0; k--) {
                dp[i][j][k] = min({dp[i][j][k],
                                dp[i+9][j+3][k+1] + 1,
                                dp[i+9][j+1][k+3] + 1,
                                dp[i+1][j+9][k+3] + 1,
                                dp[i+3][j+9][k+1] + 1,
                                dp[i+1][j+3][k+9] + 1,
                                dp[i+3][j+1][k+9] + 1});
            }
        }
    }
    cout << dp[0][0][0];
}