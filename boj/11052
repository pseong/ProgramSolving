#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    int p[10010]{ 0 };
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    
    int dp[1010]{ 0 };
    dp[1] = p[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i - j < 0) break;
            dp[i] = max(dp[i], dp[i - j] + p[j]);
        }
    }

    cout << dp[n];
}