#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp[10][110]{{0}};

    for(int i = 1; i < 10; i++)
        dp[i][1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[0][i] = dp[1][i - 1] % 1000000000;
        dp[9][i] = dp[8][i - 1] % 1000000000;
        for(int j = 1; j < 9; j++)
            dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;
    }

    int result = 0;
    for(int i = 0; i <10; i++)
        result = (result + dp[i][n]) % 1000000000;

    cout << result << '\n';
}