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

    int a, b;
    cin >> a >> b;
    for(int i=1;;i++) {
        a *= 3;
        b *= 2;
        if(a>b) {
            cout << i;
            return 0;
        }
    }
}