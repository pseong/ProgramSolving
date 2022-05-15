#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) cout << 10000 + a * 1000;
    else if (a == b) cout << 1000 + a * 100;
    else if (b == c) cout << 1000 + b * 100;
    else if (a == c) cout << 1000 + a * 100;
    else cout << max({a, b, c}) * 100;
}