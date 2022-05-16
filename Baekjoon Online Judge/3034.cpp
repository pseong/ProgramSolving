#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w, h;
    cin >> n >> w >> h;
    int len = w*w + h*h;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        a *= a;
        if (a <= len) cout << "DA\n";
        else cout << "NE\n";
    }
}