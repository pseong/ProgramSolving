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
        ll n;
        ll x;
        cin >> n >> x;
        ll sum = 0;
        vector<ll> an(n+1, 0);
        for (int i=1; i<=n; i++) {
            cin >> an[i];
            sum += an[i];
        }
        sort(an.begin(), an.end());
        ll now = n;
        ll ans = 0;
        ll day = 0;
        while (now) {
            if (sum <= x) {
                ll cal = x-sum;
                ll go = (cal/now)+1;
                ll get = now*go;
                ans += get;
                day += go;
                sum += now*go;
                sum -= an[now]+day;
                now--;
            }
            else {
                sum -= an[now]+day;
                now--;
            }
        }
        cout << ans << '\n';
    }
}