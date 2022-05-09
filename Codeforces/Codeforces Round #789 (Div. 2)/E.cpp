#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> an(n+1), bn(n+1), d(n+1);
        for (int i=1; i<=n; i++) cin >> an[i];
        for (int i=1; i<=n; i++) {
            cin >> bn[i];
            d[bn[i]] = i;
        }

        vector<int> chk(n+1, 0);
        ll cnt = 0;
        for (int i=1; i<=n; i++) {
            if (chk[i] == 0) {
                int len = 0;
                int go = i;
                while (chk[go] == 0) {
                    chk[go] = 1;
                    go = d[an[go]];
                    len++;
                }
                cnt += len/2;
            }
        }
        ll ans = 0;
        for (int i=1; i<=cnt; i++) {
            ans += (n-2*i+1)*2;
        }
        cout << ans << '\n';
    }
}