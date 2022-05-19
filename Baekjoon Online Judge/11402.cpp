#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll exgcd(ll a, ll b, ll &s, ll &t) { if (b == 0) { s = 1; t = 0; return a; } ll gcd = exgcd(b, a%b, s, t); ll tmp = t; t = s - (a / b)*t; s = tmp; if (s <= 0) { s += b; t -= a; } return gcd; }

ll com[2020][2020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, m; cin >> n >> k >> m;

    com[0][0] = 1;
    for (int i=1; i<m; i++) {
        com[i][0] = 1;
        for (int j=1; j<=i; j++) {
            com[i][j] = com[i-1][j-1] + com[i-1][j];
            com[i][j] %= m;
        }
    }

    ll ans = 1;
    while (n || k) {
        ans *= com[n%m][k%m];
        ans %= m;
        n /= m;
        k /= m;
    }
    cout << ans;
}