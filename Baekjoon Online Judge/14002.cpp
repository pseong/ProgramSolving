#include <bits/stdc++.h>

using namespace std;

int dp[1001][2]{ 0 };
int a[1001]{ 0 };

void go(int p) {
    if (p == 0) {
        return;
    }
    go(dp[p][1]);
    cout << a[p] << ' ';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int result = 1;
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 0;
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j] && dp[i][0] < dp[j][0] + 1) {
                dp[i][0] = dp[j][0] + 1;
                dp[i][1] = j;
            }
        }
        if(dp[result][0] < dp[i][0]) {
            result = i;
        }
    }

    cout << dp[result][0] << '\n';
    go(result);
}