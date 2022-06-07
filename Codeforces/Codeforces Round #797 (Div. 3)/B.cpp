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
        ll h = (n+2)/3 + 1;
        ll m = h-1;
        ll l = n-(m+h);
        if (l == 0) {
            l++;
            m--;
        }
        cout << m << ' ' << h << ' ' << l << '\n';
    }
}