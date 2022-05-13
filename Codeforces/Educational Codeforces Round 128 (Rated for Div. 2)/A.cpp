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
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a > c) {
            swap(a, c);
            swap(b, d);
        }
        if (c <= b) {
            cout << c << '\n';
        }
        else {
            cout << a + c << '\n';
        }
    }
}