#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=1000;
int n;
double l, r, dp[N+10][N+10];
bool visitt[N+10][N+10];

double dfs(int n, int x) {
    if(n==0) return x;
    if(!visitt[n][x]) {
        double left=dfs(n-1, x+1)-1;
        double mid=dfs(n-1, x);
        double right=dfs(n-1, max(0, x-1))+1;
        dp[n][x] = l*left + r*right + (1-l-r)*mid;
        visitt[n][x] = true;
    }
    return dp[n][x];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> l >> r;
        memset(visitt, 0, sizeof(visitt));
        cout << fixed << setprecision(4) << dfs(n, 0) << '\n';
    }
}