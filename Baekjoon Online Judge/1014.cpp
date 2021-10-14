#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define pb push_back
#define F first
#define S second
int n, m;
char an[10][10];
int dp[10][2000];

int dfs(int idx, int visit) {
    if(idx==n) return 0;
    if(dp[idx][visit]!=-1) return dp[idx][visit];
    int ans=0;
    for(int i=0; i<(1<<m); i++) {
        int cnt=0;
        bool bk=false;
        for(int k=0; k<m; k++) {
            if(i&(1<<k)) {
                cnt++;
                if(an[idx][k]=='x' ||
                    k>0 && i&(1<<(k-1)) ||
                    k>0 && visit&(1<<(k-1)) ||
                    k<m-1 && visit&(1<<(k+1))) {
                        bk = true;
                        break;
                    }
            }
        }
        if(bk) continue;
        ans = max(ans, cnt+dfs(idx+1, i));
    }
    return dp[idx][visit] = ans;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i=0; i<10; i++) {
            for(int j=0; j<2000; j++) {
                dp[i][j] = -1;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> an[i][j];
            }
        }
        cout << dfs(0, 0) << '\n';
    }
}