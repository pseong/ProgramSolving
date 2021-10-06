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
#include <list>
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

    int n;
    cin >> n;
    int an[20][20]{0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
        }
    }
    int dp[20][20][3]{0};
    dp[1][2][0] = 1;
    for(int j=3; j<=n; j++) {
        for(int i=1; i<=n; i++) {
            if(an[i][j]==1) continue;
            dp[i][j][0] += dp[i][j-1][0]+dp[i][j-1][1];
            if(an[i-1][j]==0 && an[i][j-1]==0)
                dp[i][j][1] += dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
            dp[i][j][2] += dp[i-1][j][1]+dp[i-1][j][2];
        }
    }
    cout << dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
}