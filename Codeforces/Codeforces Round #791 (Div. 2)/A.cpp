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
        if (n < 4 || n%2 == 1) {
            cout << -1 << '\n';
            continue;
        }
        cout << (n+5)/6 << ' ' << n/4 << '\n';
    }
}