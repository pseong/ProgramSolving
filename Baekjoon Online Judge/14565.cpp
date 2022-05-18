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

    ll n, a; cin >> n >> a;
    a %= n;
    cout << n-a << ' ';
    if (gcd(a, n) != 1) {
        cout << -1;
        return 0;
    }
    ll s, t;
    exgcd(a, n, s, t);
    ll inv = (s+n)%n;
    cout << inv << '\n';
}