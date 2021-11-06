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
        ll a, b;
        cin >> a >> b;
        ll cnt2=0;
        ll i=9;
        while(i<=b) {
            cnt2++;
            i *= 10;
            i += 9;
        }
        cout << a*cnt2 << '\n';
    }
}