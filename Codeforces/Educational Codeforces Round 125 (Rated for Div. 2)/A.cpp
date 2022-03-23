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
        if (a==0 && b==0) cout << 0 << '\n';
        else if ((int)sqrt(a*a+b*b) == sqrt(a*a+b*b)) {
            cout << 1 << '\n';
        }
        else cout << 2 << '\n';
    }
}