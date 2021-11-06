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
        ll n, d;
        cin >> n >> d;
        ll cal=d;
        for(ll x=1; x<=d; x++) {
            ll cal2=x+(d+x)/(x+1);
            if(cal2<=cal) cal = cal2;
            else break;
        }
        if(cal<=n) cout << "YES\n";
        else cout << "NO\n";
    }
}