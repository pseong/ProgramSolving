#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll n, k;
        cin >> n >> k;
        n--;
        ll ans=0;
        bool bk=false;
        for(ll l=0; l<60; l++) {
            if((1LL<<l)>k) break;
            if(n==0) break;
            if(n-(1LL<<l)>0) {
                n -= (1LL<<l);
                ans++;
            }
            else {
                n = 0;
                ans++;
                cout << ans << '\n';
                bk = true;
                break;
            }
        }
        if(bk) continue;
        ll sum=n/k;
        if(n%k>0) sum++;
        ans += sum;
        cout << ans << '\n';
    }
}