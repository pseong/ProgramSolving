#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll f(ll x) {
    if(x%4==1) return -x;
    if(x%4==2) return 1;
    if(x%4==3) return 4*(x/4+1);
    if(x%4==0) return 0;
}

ll f2(ll x) {
    if(x%4==1) return x;
    if(x%4==2) return -1;
    if(x%4==3) return -4*(x/4+1);
    if(x%4==0) return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll x, n;
        cin >> x >> n;
        if(x%2==0) {
            cout << x+f(n) << '\n';
        }
        else {
            cout << x+f2(n) << '\n';
        }
    }
}