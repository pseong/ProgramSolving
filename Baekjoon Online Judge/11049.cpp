#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll dp[550][550];
ll an[550], bn[550];
const ll inf = 1000000000000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i] >> bn[i];
    }
    for (int i=0; i<550; i++) {
        for (int j=0; j<550; j++) {
            dp[i][j] = inf;
        }
    }

    for (int i=1; i<=n; i++) {
        dp[i][i] = 0;
    }

    for (int j=1; j<=n; j++) {
        for (int i=1; i<=n-j+1; i++) {
            for (int k=1; k<=j; k++) {
                // i ~ i+j-1
                dp[i][i+j-1] = min(dp[i][i+j-1], dp[i][i+k-1] + dp[i+k][i+j-1] + an[i] * bn[i+k-1] * bn[i+j-1]);
            }
        }
    }

    cout << dp[1][n];
}