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

string an[20];
ll dp[1<<15][120]{0};
ll mod[16][101];
int n, k;

ll dfs(ll r, int visit) {
    if(visit==((1<<n)-1)) {
        if(r%k==0) return 1;
        else return 0;
    }
    if(dp[visit][r]!=-1) {
        return dp[visit][r];
    }
    dp[visit][r] = 0;
    for(int i=0; i<n; i++) {
        if(visit&(1<<i)) continue;
        ll p = mod[i][r];
        dp[visit][r] += dfs(p, visit|(1<<i));
    }
    return dp[visit][r];
}

ll gcd(ll a, ll b) {
    while(b!=0) {
        a = a%b;
        swap(a, b);
    }
    return a;
}

ll factorial(ll a) {
    ll res=1;
    for(ll i=1; i<=a; i++) {
        res *= i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(ll i=0; i<n; i++) {
        cin >> an[i];
    }
    cin >> k;
	for(int i=0 ; i<n; i++){	
		int len = an[i].length();
		for(int j=0 ; j<=k; j++){
			ll cnt = j % k ;
			for(int a=0 ; a<len; a++){
				cnt = cnt*10 + (an[i][a]-'0');
				cnt %= k;
			}
			mod[i][j]  = cnt;
		}
	}
    memset(dp, -1, sizeof(dp));
    ll ans=dfs(0, 0);
    ll a=gcd(ans, factorial(n));
    cout << ans/a << '/' << factorial(n)/a;
}