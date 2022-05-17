#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    ll x = m / n;
    ll a = -1;
    ll b = -1;
    for (int i=1; i*i<=x; i++) {
        if (x%i == 0 && gcd(i, x/i) == 1) {
            a = i*n;
            b = x/i*n;
        }
    }
    cout << a << ' ' << b;
}