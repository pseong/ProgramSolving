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
        ll n, k; cin >> n >> k;
        vector<ll> v(n+1), sum(n+1);
        for (int i=1; i<=n; i++) {
            cin >> v[i];
            sum[i] = sum[i-1] + v[i];
        }
        if (k <= n) {
            ll mx = 0;
            for (int i=k; i<=n; i++) {
                mx = max(mx, sum[i] - sum[i-k]);
            }
            cout << mx + (k-1)*k/2 << '\n';
        }
        else {
            ll ans = sum[n];
            ans += n*(n+1)/2;
            ans += (k-n-1)*n;
            cout << ans << '\n';
        }
    }
}