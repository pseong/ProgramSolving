#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    long long dp[2][100]{{ 0 }};

    dp[0][1] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
    }

    long long  result = 0;
    for(int i = 0; i < 2; i++)
        result += dp[i][n];

    cout << result << '\n';
}