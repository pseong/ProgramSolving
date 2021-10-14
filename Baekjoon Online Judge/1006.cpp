#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define pb push_back
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, w;
        cin >> n >> w;
        int an[10010]{0};
        int an2[10010]{0};
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        for(int i=1; i<=n; i++) {
            cin >> an2[i];
        }
        an[0] = an[n];
        an2[0] = an2[n];
        int dp[10010][5]{0};
        for(int i=1; i<=n; i++) {
            for(int j=0; j<5; j++) {
                dp[i][j] = 1000000000;
            }
        }
        dp[1][0] = 2;
        if(an[1]+an2[1]<=w)  dp[1][1] = 1;
        //if(an[1]+an[0]<=w) dp[1][2] = 2;
        //if(an2[1]+an2[0]<=w) dp[1][3] = 2;
        //if(an[1]+an[0]<=w && an2[1]+an2[0]<=w) dp[1][4] = 2;

        for(int i=2; i<=n; i++) {
            dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+2;
            if(an[i]+an2[i]<=w) {
                dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+1;
            }
            if(an[i]+an[i-1]<=w) {
                dp[i][2] = min({dp[i][2], dp[i-1][0]+1, dp[i-1][3]+1});
            }
            if(an2[i]+an2[i-1]<=w) {
                dp[i][3] = min({dp[i][3], dp[i-1][0]+1, dp[i-1][2]+1});
            }
            if(an[i]+an[i-1]<=w && an2[i]+an2[i-1]<=w) {
                dp[i][4] = min({dp[i][4], dp[i-1][0]});
            }
        }

        int ans=1000000000;
        for(int i=0; i<5; i++) {
            ans = min(ans, dp[n][i]);
        }
        if(n>1) {
            if(an[1]+an[0]<=w) {
                for(int i=1; i<=n; i++) {
                    for(int j=0; j<5; j++) {
                        dp[i][j] = 1000000000;
                    }
                }
                dp[1][2] = 1;
                for(int i=2; i<=n; i++) {
                    dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+2;
                    if(an[i]+an2[i]<=w) {
                        dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+1;
                    }
                    if(an[i]+an[i-1]<=w) {
                        dp[i][2] = min({dp[i][2], dp[i-1][0]+1, dp[i-1][3]+1});
                    }
                    if(an2[i]+an2[i-1]<=w) {
                        dp[i][3] = min({dp[i][3], dp[i-1][0]+1, dp[i-1][2]+1});
                    }
                    if(an[i]+an[i-1]<=w && an2[i]+an2[i-1]<=w) {
                        dp[i][4] = min({dp[i][4], dp[i-1][0]});
                    }
                }
                ans = min(ans, dp[n][0]);
                ans = min(ans, dp[n][3]);
            }

            if(an2[1]+an2[0]<=w) {
                for(int i=1; i<=n; i++) {
                    for(int j=0; j<5; j++) {
                        dp[i][j] = 1000000000;
                    }
                }
                dp[1][3] = 1;
                for(int i=2; i<=n; i++) {
                    dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+2;
                    if(an[i]+an2[i]<=w) {
                        dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+1;
                    }
                    if(an[i]+an[i-1]<=w) {
                        dp[i][2] = min({dp[i][2], dp[i-1][0]+1, dp[i-1][3]+1});
                    }
                    if(an2[i]+an2[i-1]<=w) {
                        dp[i][3] = min({dp[i][3], dp[i-1][0]+1, dp[i-1][2]+1});
                    }
                    if(an[i]+an[i-1]<=w && an2[i]+an2[i-1]<=w) {
                        dp[i][4] = min({dp[i][4], dp[i-1][0]});
                    }
                }
                ans = min(ans, dp[n][0]);
                ans = min(ans, dp[n][2]);
            }

            if(an[1]+an[0]<=w && an2[1]+an2[0]<=w) {
                for(int i=1; i<=n; i++) {
                    for(int j=0; j<5; j++) {
                        dp[i][j] = 1000000000;
                    }
                }
                dp[1][4] = 2;
                for(int i=2; i<n; i++) {
                    dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+2;
                    if(an[i]+an2[i]<=w) {
                        dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]})+1;
                    }
                    if(an[i]+an[i-1]<=w) {
                        dp[i][2] = min({dp[i][2], dp[i-1][0]+1, dp[i-1][3]+1});
                    }
                    if(an2[i]+an2[i-1]<=w) {
                        dp[i][3] = min({dp[i][3], dp[i-1][0]+1, dp[i-1][2]+1});
                    }
                    if(an[i]+an[i-1]<=w && an2[i]+an2[i-1]<=w) {
                        dp[i][4] = min({dp[i][4], dp[i-1][0]});
                    }
                }
                for(int i=0; i<5; i++) {
                    ans = min(ans, dp[n-1][i]);
                }
            }
        }
        cout << ans << '\n';
    }
}