#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll ans = 0;
        for (int i=0; i<=30; i++) {
            if (n & (1LL<<i)) {
                ans |= (1LL<<i);
                break;
            }
        }

        if ((ans ^ n) == 0) {
            for (int i=0; i<=30; i++) {
                if (n & (1LL<<i)) {
                }
                else {
                    ans |= (1LL<<i);
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
}