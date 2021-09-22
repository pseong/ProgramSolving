#include <iostream>

using namespace std;

int dp[101][10001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int mn[101]{0};
    int cn[101]{0};

    for(int i=1; i<=n; i++) {
        cin >> mn[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> cn[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=10000; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-cn[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-cn[i]]+mn[i]);
        }
    }

    for(int i=1; i<=10000; i++) {
        if(dp[n][i]>=m) {
            cout << i;
            break;
        }
    }
}