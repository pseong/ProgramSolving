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

    int dp[50]{0};
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=45; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    int n;
    cin >> n;
    cout << dp[n];
}