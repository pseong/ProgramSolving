#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int dp[210][210]{{ 0 }};
    dp[1][n] = 1;
    for(int i = 2; i <= k; i++)
        for(int j = 0; j <= n; j++)
            if(dp[i - 1][j])
                for(int z = 0; z <= j; z++)
                    dp[i][z] = (dp[i][z] + dp[i - 1][j]) % 1000000000;

    int result = 0;
    for(int i = 0; i <= n; i++) {
        result = (result + dp[k][i]) % 1000000000;
    }
    cout << result;
}