#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

typedef long long ll;
typedef long double ld;

using namespace std;

ld an[20][20]{0};
ld dp[20][1<<16]{0};
int n;

ld dfs(int node, int visit, int start) {
    if(visit==((1<<n)-1)) return 0;
    if(dp[node][visit]!=-1) return dp[node][visit];
    ld ans=100000;
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

    vector<pair<int, int>> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            ld dx=(v[i].first-v[j].first);
            ld dy=(v[i].second-v[j].second);
            ld a=sqrt(dx*dx+dy*dy);
            an[i][j] = a;
            an[j][i] = a;
        }
    }
    ld ans=100000;
    for(int i=0; i<n; i++) {
        for(int k=0; k<19; k++) {
            for(int m=0; m<(1<<16); m++) {
                dp[k][m] = -1;
            }
        }
        ans = min(ans, dfs(i, 0, i));
    }
    cout << fixed << setprecision(10) << ans;
}