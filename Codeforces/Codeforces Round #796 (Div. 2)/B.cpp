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
        vector<ll> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        ll cnt = -1;
        ll idx = -1;
        for (int i=0; i<n; i++) {
            ll res = 0;
            ll go = v[i];
            while (go%2 == 0) {
                go /= 2;
                res++;
            }
            if (cnt == -1) {
                cnt = res;
                idx = i;
            }
            else {
                if (cnt > res) {
                    cnt = res;
                    idx = i;
                }
            }
        }
        ll ans = 0;
        for (int i=0; i<n; i++) {
            if (i == idx) continue;
            if (v[i]%2 == 0) {
                ans++;
            }
        }
        cout << ans + cnt << '\n';
    }
}