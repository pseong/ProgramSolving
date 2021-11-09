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

    int n;
    cin >> n;
    int c=0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        c = __gcd(c, a);
    }
    for(int i=1; i<=c; i++) {
        if(c%i==0) {
            cout << i << '\n';
        }
    }
}