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
        int a, b;
        cin >> a >> b;
        if(a<=b) cout << b-a << '\n';
        else {
            a -= (a/b)*b;
            if(a==0) a += b;
            cout << b-a << '\n';
        }
    }
}