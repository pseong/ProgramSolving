#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    int a[1001]{ 0 };
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int result = 1;
    int dp[1001][2]{ 0 };
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
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

    int ans[1000]{ 0 };
    int cnt = 0;
    int ans2 = result;
    while(dp[result][1] != result) {
        ans[cnt] = a[result];
        result = dp[result][1];
        cnt++;
    }
    ans[cnt] = a[result];
    cnt++;

    cout << dp[ans2][0] << '\n';
    for(int i = cnt - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
}