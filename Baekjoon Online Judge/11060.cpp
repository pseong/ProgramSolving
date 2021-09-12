#include <iostream>
#include <cstring>


using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int a[1001]{0};
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    if(n==1) {
        cout << 0;
        return 0;
    }
    int dp[1001]{0};
    memset(dp, -1, sizeof(dp));

    dp[1]=0;
    for(int i=1; i<=n; i++) {
        if(dp[i]==-1) continue;
        for(int j=1; j<=a[i]; j++) {
            if(i+j>n) continue;
            if(dp[i+j]==-1) dp[i+j] = dp[i]+1;
            else dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    cout << dp[n];
}