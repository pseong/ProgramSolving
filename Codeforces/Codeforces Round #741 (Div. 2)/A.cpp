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
        int l, r;
        cin >> l >> r;
        if(l*2<=(r+1)) {
            cout << (r+1)/2-1 << '\n';
        }
        else {
            cout << r-l << '\n';
        }
    }
}