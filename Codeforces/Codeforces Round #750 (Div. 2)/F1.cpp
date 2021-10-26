#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
const int inf=1000000000;
int n, an[N+10], dp[520];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for(int i=1; i<=512; i++) {
        dp[i] = inf;
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=512; j++) {
            if(dp[j] < an[i]) {
                dp[j^an[i]] = min(dp[j^an[i]], an[i]);
            }
        }
    }
    ans.push_back(0);
    for(int i=1; i<=512; i++) {
        if(dp[i]!=inf) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int i : ans) {
        cout << i << ' ';
    }
}
