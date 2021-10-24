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
        int n;
        cin >> n;
        ll an[100]{0};
        ll one=0;
        ll zero=0;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
            if(an[i]==1) one++;
            else if(an[i]==0) zero++;
        }
        ll p=1;
        for(int i=1; i<=zero; i++) {
            p *= 2;
        }
        cout << one*p << '\n';
    }
}