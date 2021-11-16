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

    ll n;
    cin >> n;
    if(n&1) {
        cout << -(n+1)/2;
    }
    else {
        cout << (n+1)/2;
    }
}