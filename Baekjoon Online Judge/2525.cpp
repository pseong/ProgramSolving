#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;
    y += z;
    x += y/60;
    y %= 60;
    x %= 24;
    cout << x << ' ' << y;
}