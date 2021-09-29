#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <tuple>

typedef long long ll;
typedef long double ld;

using namespace std;

int dp[25][1<<20]{0};
int an[25][25]{0};
int n;

int dfs(int idx, int visit) {
    if(idx==n) return 0;
    if(dp[idx][visit]!=-1) return dp[idx][visit];
    int ans=1000000000;
    for(int i=0; i<n; i++) {
        if(visit & (1<<i)) continue;
        ans = min(ans, dfs(idx+1, visit | (1<<i))+an[idx][i]);
    }
    dp[idx][visit] = ans;
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> an[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
}