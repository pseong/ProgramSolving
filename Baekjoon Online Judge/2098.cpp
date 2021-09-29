#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <tuple>

typedef long long ll;
typedef long double ld;

using namespace std;

int an[20][20]{0};
int dp[20][1<<16]{0};
int n;

int dfs(int node, int visit, int start) {
    if(visit==((1<<n)-1)) return 0;
    if(dp[node][visit]!=-1) return dp[node][visit];
    int ans=2000000000;
    for(int i=0; i<n; i++) {
        if(!an[node][i]) continue;
        if(visit & (1<<i)) continue;
        if(i==start&&(visit|(1<<i))!=((1<<n)-1)) continue;
        ans=min(ans, dfs(i, visit|(1<<i), start)+an[node][i]);
    }
    dp[node][visit] = ans;
    return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> an[i][j];
        }
    }
    int ans=2000000000;
    for(int i=0; i<n; i++) {
        memset(dp, -1, sizeof(dp));
        ans = min(ans, dfs(i, 0, i));
    }
    cout << ans;
}