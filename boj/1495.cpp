#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v[101]{0};
    int n, s, m;
    cin >> n >> s >> m;
    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }
    bool dp[101][1001]{0};
    dp[0][s] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(j-v[i]>=0) dp[i][j] += dp[i-1][j-v[i]];
            if(j+v[i]<=m) dp[i][j] += dp[i-1][j+v[i]];
        }
    }
    for(int i=m; i>=0; i--) {
        if(dp[n][i]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}