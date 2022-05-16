#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int d(int x1, int y1, int x2, int y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n; cin >> n;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            int a = (d(x1, y1, x, y) <= r*r) ? 1 : 0;
            int b = (d(x2, y2, x, y) <= r*r) ? 1 : 0;
            if (a != b) cnt++;
        }
        cout << cnt << '\n';
    }
}