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
        if (a==0 && b==0) {
            cout << 0 << '\n';
            continue;
        }
        
        int d = a*a + b*b;
        bool chk = false;
        for (int i=1; i<=100; i++) {
            if (i*i == d) chk = true;
        }
        if (chk) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}