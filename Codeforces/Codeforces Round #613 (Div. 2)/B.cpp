#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
ll an[N+10], sum[N+10], dp[N+10];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
            sum[i] = sum[i-1] + an[i];
        }
        ll y=sum[n];

        ll mx=-1000000000;
        ll end_s=0;
        for(int i=1; i<=n-1; i++) {
            end_s = max(end_s+an[i], an[i]);
            mx = max(end_s, mx);
        }
        end_s=0;
        for(int i=2; i<=n; i++) {
            end_s = max(end_s+an[i], an[i]);
            mx = max(end_s, mx);
        }
        if(y>mx) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}