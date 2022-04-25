#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while (T--) {
        ll n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;
        if (y*b > z*a) {
            swap(a, b);
            swap(y, z);
        }
        ll cost = n*x;
        if (a*a <= n) {
            for (ll cntB=0; cntB<a; cntB++) {
                if (b*cntB > n) break;
                ll cntA = (n-b*cntB)/a;
                ll left = n-a*cntA-b*cntB;
                cost = min(cost, y*cntA + z*cntB + x*left);
            }
        }
        else {
            for (ll cntA=0; cntA<=n/a; cntA++) {
                ll cntB = (n-a*cntA)/b;
                ll left = n-a*cntA-b*cntB;
                cost = min(cost, y*cntA + z*cntB + x*left);
            }
        }
        cout << cost << '\n';
    }
}