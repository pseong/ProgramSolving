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
        int n, b, x, y;
        cin >> n >> b >> x >> y;
        ll ans = 0;
        int now = 0;
        for (int i=0; i<n; i++) {
            if (now + x <= b) {
                now += x;
            }
            else {
                now -= y;
            }
            ans += now;
        }
        cout << ans << '\n';
    }
}