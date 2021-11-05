#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll x;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> x;
    for(ll i=sqrt(x); i>=0; i--) {
        if(x%i==0) {
            ll a=i;
            ll b=x/i;
            if(a*b/__gcd(a, b)==x) {
                cout << a << ' ' << b;
                break;
            }
        }
    }
}