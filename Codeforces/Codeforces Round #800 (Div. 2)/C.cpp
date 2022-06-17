#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        bool ok = true;
        int now = 0;
        for (int i=0; i<n; i++) {
            if (v[i] < -now) ok = false;
            now = v[i] + now;
            if (now == 0) {
                for (int j=i+1; j<n; j++) {
                    if (v[j] != 0) ok = false;
                }
                break;
            }
        }
        if (now != 0) ok = false;
        if (ok) cout << "yes\n";
        else cout << "no\n";
    }
}