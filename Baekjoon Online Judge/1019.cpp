#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define pb push_back
#define F first
#define S second

ll ans[10];
ll n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(ll i=10; i<=10000000000; i*=10) {
        ll div=n/i;
        for(ll k=0; k<10; k++) {
            ans[k] += div*i/10;
        }
        if(div>=1) ans[0] -= (i/10-1);
        ll left=n%i;
        if(div>=1) {
            ll div2=left/(i/10);
            for(ll k=1; k<div2; k++) {
                ans[k] += i/10;
            }
            if(div2>=1) ans[0] += (i/10-1);
            if(div2==0) {
                ll left2=left%(i/10);
                ans[div2] += left2;
            }
            else {
                ll left2=left%(i/10)+1;
                ans[div2] += left2;
            }
        }
        else {
            ll div2=left/(i/10);
            if(div2==0) continue;
            for(ll k=1; k<div2; k++) {
                ans[k] += i/10;
            }
            ll left2=left%(i/10)+1;
            ans[div2] += left2;
        }
    }
    for(ll i=0; i<10; i++) {
        cout << ans[i] << ' ';
    }
}