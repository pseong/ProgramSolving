#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
const int inf=2000000000;
ll an[N+5];
ll dp[N+5][450];
ll pref[N+5];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
            pref[i] = pref[i-1] + an[i];
        }
        k = 1;
        while(k*(k+1)<=n*2) k++;
        for (int j=0; j<k; j++) {
            dp[n+1][j] = -inf;
        }
        for(int i=1; i<=n+1; i++) {
            dp[i][0] = inf;
        }
        for(int i=n; i>=1; i--) {
            for(int j=1; j<k; j++) {
                dp[i][j] = dp[i+1][j];
                if(i+j-1<=n && pref[i+j-1]-pref[i-1] < dp[i+j][j-1]) {
                    dp[i][j] = max(dp[i][j], pref[i+j-1]-pref[i-1]);
                }
            }
        }
        int ans=0;
        for(int i=1; i<k; i++) {
            if(dp[1][i]>0) ans = i;
        }
        cout << ans << '\n';
    }
}
