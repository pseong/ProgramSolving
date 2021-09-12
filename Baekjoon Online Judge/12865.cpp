#include <iostream>

using namespace std;

int dp[101][100001]{0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w[101]{0};
    int v[101]{0};
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        w[i] = a;
        v[i] = b;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-w[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
        }
    }
    int ans=0;
    for(int j=1; j<=k; j++) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans;
}