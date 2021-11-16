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

    int mx=0;
    int mx_idx=1;
    int mn=100;
    int mn_idx=1;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if(a>mx) {
            mx = a;
            mx_idx = i;
        }
        if(a<=mn) {
            mn = a;
            mn_idx = i;
        }
    }
    int add=0;
    if(mx_idx>mn_idx) add = -1;
    cout << mx_idx-1+n-mn_idx+add;
}