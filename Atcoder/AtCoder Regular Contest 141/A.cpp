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
        string s = to_string(n);
        int sz = s.size();
        string as = string(sz-1, '9');
        ll ans = stoll(as);
        for (int i=1; i<=sz-1; i++) {
            if (sz%i != 0) continue;
            string p = s.substr(0, i);
            string pp;
            for (int k=0; k<sz/i; k++) {
                pp += p;
            }
            if (stoll(pp) > n) {
                ll tmp = stoll(p);
                tmp--;
                p = to_string(tmp);
                pp.clear();
                for (int k=0; k<sz/i; k++) {
                    pp += p;
                }
            }
            ans = max(ans, stoll(pp));
        }
        cout << ans << '\n';
    }
}