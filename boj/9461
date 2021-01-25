#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;

    long long dp[110] {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 0, };

    for(int i = 11; i <= 105; i++)
        dp[i] = dp[i - 1] + dp[i - 5];

    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}