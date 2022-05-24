#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> an(n);
        for (int i=0; i<n; i++) cin >> an[i];

        ll sum = 0;
        int m; cin >> m;
        for (ll i=0; i<m; i++) {
            ll a; cin >> a;
            sum += a;
        }
        sum %= n;
        cout << an[sum] << '\n';
    }
}