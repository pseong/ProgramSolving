#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int x, y;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> x >> y;
        if(x==y) {
            cout << x << '\n';
        }
        else if(x>y) {
            cout << x+y << '\n';
        }
        else {
            cout << y-(y%x)/2 << '\n';
        }
    }
}