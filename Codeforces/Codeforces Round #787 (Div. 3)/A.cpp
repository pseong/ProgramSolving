#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        x -= min(a, x);
        y -= min(b, y);
        if (c >= x+y) cout << "YES\n";
        else cout << "NO\n";
    }
}