#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp[10][1010]{{ 0 }};

    for(int i = 0; i < 10; i++)
        dp[i][1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] % 10007;
        for(int j = 1; j <= 9; j++)
            for(int k = 0; k <= j; k++)
                dp[j][i] += dp[k][i - 1] % 10007;
    }

    int result = 0;
    for(int i = 0; i <10; i++)
        result = (result + dp[i][n]) % 10007;

    cout << result << '\n';
}