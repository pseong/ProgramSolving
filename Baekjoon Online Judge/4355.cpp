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

    ll n;
    while(cin >> n) {
        if(n==0) break;
        ll ans=n;
        for(int i=2; i*i<=n; i++) {
            if(n%i==0) {
                ans -= ans/i;
                while(n%i==0) n /= i;
            }
        }
        if(n>1) ans -= ans/n;
        cout << ans << '\n';
    }
}