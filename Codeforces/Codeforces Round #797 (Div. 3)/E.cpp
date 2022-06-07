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
        multiset<ll> s;
        ll ans = 0;
        for (int i=0; i<n; i++) {
            ll a; cin >> a;
            ans += a / k;
            s.insert(a % k);
        }

        while (s.size()) {
            ll x = *s.begin();
            s.erase(s.begin());
            auto it = s.lower_bound(k-x);
            if (it != s.end()) {
                s.erase(it);
                ans++;
            }
        }

        cout << ans << '\n';
    }
}