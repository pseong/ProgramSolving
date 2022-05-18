#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll exgcd(ll a, ll b, ll &s, ll &t) { if (b == 0) { s = 1; t = 0; return a; } ll gcd = exgcd(b, a%b, s, t); ll tmp = t; t = s - (a / b)*t; s = tmp; if (s <= 0) { s += b; t -= a; } return gcd; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        ll k, c; cin >> k >> c;
        if (gcd(k, c) != 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        ll s, t;
        exgcd(c, k, s, t);
        ll inv = (s+k)%k;
        while (c*inv <= k) inv += k;
        if (inv > 1e9) cout << "IMPOSSIBLE\n";
        else cout << inv << '\n';
    }
}