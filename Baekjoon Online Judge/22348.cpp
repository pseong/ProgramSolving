#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int MOD = 1000000007;
int dp[510][50010];
int prefix_dp[510][50010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    dp[0][0] = 1;
    for (int i=1; i<501; i++) {
        for (int j=0; j<50001; j++) {
            if (j+i <= 50001) {
                dp[i][j+i] = (dp[i][j+i]+dp[i-1][j]) % MOD;
            }
            dp[i][j] = (dp[i][j]+dp[i-1][j]) % MOD;
        }
    }

    for (int i=1; i<501; i++) {
        prefix_dp[i][0] = dp[i][0];
        for (int j=1; j<50001; j++) {
            prefix_dp[i][j] = (prefix_dp[i][j-1]+dp[i][j]) % MOD;
        }
    }

    int T; cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int ans=0;
        for (int i=1; i<501; i++) {
            int all = i*(i+1)/2;
            if (all-b <= a) {
                if (all-b-1 < 0) {
                    ans = (ans+prefix_dp[i][a]) % MOD;
                }
                else {
                    int sum = prefix_dp[i][a]-prefix_dp[i][all-b-1];
                    if (sum < 0) sum = MOD + sum;
                    ans = (ans+sum) % MOD;
                }
            }
        }
        cout << ans << '\n';
    }
}