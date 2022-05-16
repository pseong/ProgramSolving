#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int d(int x, int y, int a, int b) {
    return (x-a)*(x-a) + (y-b)*(y-b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;
    int r = h/2;
    int cnt = 0;
    for (int i=0; i<p; i++) {
        int a, b;
        cin >> a >> b;
        if (a>=x && a<=x+w && b>=y && b<=y+h) {
            cnt++;
        }
        else if (d(a, b, x, y+r) <= r*r) {
            cnt++;
        }
        else if (d(a, b, x+w, y+r) <= r*r) {
            cnt++;
        }
    }
    cout << cnt;
}