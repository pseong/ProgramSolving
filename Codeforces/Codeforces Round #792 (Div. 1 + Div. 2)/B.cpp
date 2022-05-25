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
        ll a, b, c; cin >> a >> b >> c;
        ll z = c;
        ll y = z + b;
        ll x = y + a;
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}