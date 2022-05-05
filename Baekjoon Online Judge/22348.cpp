#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int dp[505][50505];
int predp[505][50505];
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[0][0] = 1;
    for (int i=1; i<=500; i++) {
        for (int j=0; j<=50000; j++) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            if (j-i >= 0) {
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= mod;
            }
        }
    }

    for (int i=1; i<=500; i++) {
        predp[i][0] = dp[i][0];
        for (int j=1; j<=50000; j++) {
            predp[i][j] = predp[i][j-1] + dp[i][j];
            predp[i][j] %= mod;
        }
    }

    int T; cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i=1; i<=500; i++) {
            int all = i*(i+1)/2;
            if (all <= a+b) {
                if (all <= b) {
                    ans += predp[i][a];
                    ans %= mod;
                }
                else {
                    int sum = predp[i][a] - predp[i][all-b-1];
                    if (sum < 0) sum += mod;
                    ans += sum;
                    ans %= mod;
                }
            }
        }
        cout << ans << '\n';
    }
}