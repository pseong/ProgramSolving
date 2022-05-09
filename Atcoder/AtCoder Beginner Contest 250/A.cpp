#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int r, c;
    cin >> a >> b;
    cin >> r >> c;
    int ans = 0;
    if (r != 1) ans++;
    if (r != a) ans++;
    if (c != 1) ans++;
    if (c != b) ans++;
    cout << ans << '\n';
}