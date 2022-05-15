#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll inf = 1000000000000000000ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> an(n+1);
    for (int i=1; i<=n; i++) cin >> an[i];
    ll ans = inf;
    vector<vector<ll>> dp(n+1, vector<ll>(2, inf));

    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + an[i];
    }
    ans = min(ans, dp[n][0]);


    dp.resize(n+1, vector<ll>(2, inf));
    dp[0][1] = 0;
    for (int i=1; i<=n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + an[i];
    }
    ans = min({ans, dp[n][1]});
    cout << ans;
}