#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    int a[500]{ 0 };
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int dp[500]{ 0 };
    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    for(int i = 3; i <= n; i++)
        dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);

    cout << dp[n];
}