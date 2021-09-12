#include <iostream>
#include <cstring>

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
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int j=1; j<=n; j++) {
        for(int i=1; i<=k; i++) {
            if(i-an[j]>=0&&dp[i-an[j]]>=0) {
                if(dp[i]==-1) dp[i] = dp[i-an[j]]+1;
                else dp[i] = min(dp[i], dp[i-an[j]]+1);
            }
        }
    }
    cout << dp[k];
}