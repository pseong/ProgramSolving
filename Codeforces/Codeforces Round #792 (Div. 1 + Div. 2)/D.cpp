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
        int n, k; cin >> n >> k;
        vector<int> an(n+1);
        ll ans = 0;
        for (int i=1; i<=n; i++) {
            cin >> an[i];
            ans += an[i];
        }
        vector<int> bn;
        for (int i=1; i<=n; i++) {
            bn.push_back(-an[i] + n - i);
        }
        sort(bn.begin(), bn.end());
        for (int i=0; i<k; i++) {
            if (bn[i] - i < 0) {
                ans += bn[i] - i;
            }
            else break;
        }
        cout << ans << '\n';
    }
}