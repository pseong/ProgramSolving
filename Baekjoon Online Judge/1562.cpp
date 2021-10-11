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
using pdd = pair<double, double>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int n;
int dp[101][10][1100];

ll dfs(int idx, int now, int visit) {
    if(dp[idx][now][visit]!=-1) {
        return dp[idx][now][visit];
    }
    if(idx==n) {
        if(visit==(1<<10)-1) {
            dp[idx][now][visit] = 1;
            return dp[idx][now][visit];
        } else {
            dp[idx][now][visit] = 0;
            return dp[idx][now][visit];
        }
    }
    ll res=0;
    if(now-1>=0) {
        res += dfs(idx+1, now-1, visit|(1<<(now-1)));
        res %= 1000000000;
    }
    if(now+1<=9) {
        res += dfs(idx+1, now+1, visit|(1<<(now+1)));
        res %= 1000000000;
    }
    dp[idx][now][visit] = res;
    return dp[idx][now][visit];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    ll res=0;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=9; i++) {
        res += dfs(1, i, (1<<i));
        res %= 1000000000;
    }
    cout << res;
}