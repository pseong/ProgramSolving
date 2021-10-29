#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=10;
int an[N+10];
ll max_get[N+10];

ll poww(ll a, ll b) {
    ll ret=1;
    for(int i=0; i<b; i++) {
        ret *= a;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        for(int i=1; i<n; i++) {
            int diff=an[i+1]-an[i];
            max_get[i] = poww(10, diff)-1;
        }
        
        int want=k+1;
        ll ans=0;
        for(int i=1; i<=n; i++) {
            if(i==n) {
                ans += want*poww(10, an[i]);
                break;
            }
            if(want-max_get[i]>=0) {
                want -= max_get[i];
                ans += max_get[i]*poww(10, an[i]);
            }
            else {
                ans += want*poww(10, an[i]);
                break;
            }
        }
        cout << ans << '\n';
    }
}