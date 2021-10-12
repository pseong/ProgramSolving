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

int an[100010];
int dp[100010][10];
int n=1;

int getState(int a, int b) {
    if(a>b) swap(a, b);
    if(a==0) {
        if(b==1) return 0;
        if(b==2) return 1;
        if(b==3) return 2;
        if(b==4) return 3;
    }
    if(a==1) {
        if(b==2) return 4;
        if(b==3) return 5;
        if(b==4) return 6;
    }
    if(a==2) {
        if(b==3) return 7;
        if(b==4) return 8;
    }
    if(a==3) {
        if(b==4) return 9;
    }
}

pii getReverse(int k) {
    if(k==0) return {0, 1};
    if(k==1) return {0, 2};
    if(k==2) return {0, 3};
    if(k==3) return {0, 4};
    if(k==4) return {1, 2};
    if(k==5) return {1, 3};
    if(k==6) return {1, 4};
    if(k==7) return {2, 3};
    if(k==8) return {2, 4};
    if(k==9) return {3, 4};
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for(;;n++) {
        cin >> an[n];
        if(an[n]==0) break;
    }
    n--;
    if(n==0) {
        cout << 0;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<100010; i++) {
        for(int j=0; j<10; j++) {
            dp[i][j] = 1000000000;
        }
    }

    int mirror[]{0, 3, 4, 1, 2};

    dp[1][getState(0, an[1])] = 2;

    for(int i=2; i<=n; i++) {
        int now=an[i];
        for(int k=0; k<10; k++) {
            if(dp[i-1][k]!=1000000000) {
                int a, b;
                tie(a, b) = getReverse(k);
                if(a==now||b==now) {
                    dp[i][k] = min(dp[i][k], dp[i-1][k]+1);
                }
                else {
                    if(a>b) swap(a, b);
                    if(a==0) {
                        if(b==mirror[now])
                            dp[i][getState(now, a)] = min({dp[i][getState(now, a)], dp[i-1][k]+4});
                        else
                            dp[i][getState(now, a)] = min({dp[i][getState(now, a)], dp[i-1][k]+3});
                        dp[i][getState(now, b)] = min({dp[i][getState(now, b)], dp[i-1][k]+2});
                    }
                    else {
                        if(b==mirror[now]) swap(a, b);
                        if(a==mirror[now]) {
                            dp[i][getState(now, b)] = min(dp[i][getState(now, b)], dp[i-1][k]+4);
                            dp[i][getState(now, a)] = min(dp[i][getState(now, a)], dp[i-1][k]+3);
                        }
                        else {
                            dp[i][getState(now, a)] = min(dp[i][getState(now, a)], dp[i-1][k]+3);
                            dp[i][getState(now, b)] = min(dp[i][getState(now, b)], dp[i-1][k]+3);
                        }
                    }
                }
            }
        }
    }

    int ans=1000000000;
    for(int k=0; k<10; k++) {
        int a, b;
        tie(a, b) = getReverse(k);
        if(a==an[n]||b==an[n]) ans = min(ans, dp[n][k]);
    }
    cout << ans;
}