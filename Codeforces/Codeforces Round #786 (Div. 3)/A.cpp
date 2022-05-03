#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (y%x) cout << "0 0\n";
        else cout << 1 << ' ' << y/x << '\n';
    }
}