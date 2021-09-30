#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int n, k;
ll dp[1010][1010][2]{0}; //현재위치, 앞에서 몇개 썼는지지

ll dfs(int idx, int cnt, bool before) {
    if(cnt==k) return 1;
    else if(idx==n) return 0;
    else if(dp[idx][cnt][before]!=-1) return dp[idx][cnt][before];
    dp[idx][cnt][before] = 0;
    if(before==0) dp[idx][cnt][before] += dfs(idx+1, cnt+1, 1);
    dp[idx][cnt][before] %= 1000000003;
    dp[idx][cnt][before] += dfs(idx+1, cnt, 0);
    dp[idx][cnt][before] %= 1000000003;
    return dp[idx][cnt][before];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    ll ans=0;
    ans += dfs(1, 0, 0);
    ans %= 1000000003;
    n--;
    memset(dp, -1, sizeof(dp));
    ans += dfs(1, 1, 1);
    ans %= 1000000003;
    cout << ans;
}