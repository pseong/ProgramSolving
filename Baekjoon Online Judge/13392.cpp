#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }


int dp[10101][10]{ 0 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string an, bn;
    for (int i=0; i<=10000; i++) {
        for (int j=0; j<10; j++) {
            dp[i][j] = 1000000000;
        }
    }
    dp[0][0] = 0;
    cin >> an >> bn;
    an.insert(an.begin(), 0);
    bn.insert(bn.begin(), 0);
    for (int i=1; i<=n; i++) {
        for (int j=0; j<10; j++) {
            int lcnt = (an[i]-bn[i]+j+10)%10;
            int rcnt = 10 - lcnt;
            dp[i][j] = min(dp[i][j], dp[i-1][j] + lcnt);
            dp[i][(j+rcnt)%10] = min(dp[i][(j+rcnt)%10], dp[i-1][j]+rcnt);
        }
    }
    int ans = INT_MAX;
    for (int i=0; i<10; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
}