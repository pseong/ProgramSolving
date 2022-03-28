#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;

        if (n & 1) {
            cout << 0 << '\n';
            continue;
        }

        ll ans = 1;
        for (int i=1; i<=n/2; i++) {
            ans *= i;
            ans %= mod;
        }
        ans *= ans;
        ans %= mod;
        cout << ans << '\n';
    }
}