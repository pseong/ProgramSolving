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

    ll k, n, w;
    cin >> k >> n >> w;
    ll need=w*(w+1)/2*k;
    cout << max(0LL, need-n);
}