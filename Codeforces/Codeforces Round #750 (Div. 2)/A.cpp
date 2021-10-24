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
        int a, b, c;
        cin >> a >> b >> c;
        int s=a+b*2+c*3;
        if(s&1) cout << 1;
        else cout << 0;
        cout << '\n';
    }
}