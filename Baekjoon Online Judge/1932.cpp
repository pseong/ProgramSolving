#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int dp[501][501]{1};
    int a[501][501]{1};
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(dp[n][i] > ans) ans = dp[n][i];
    }

    cout << ans;
}