#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int minus = 0;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            if (v[i] < 0) minus++;
            v[i] = abs(v[i]);
        }
        for (int i=0; i<n; i++) {
            if (minus) {
                minus--;
                v[i] = -v[i];
            }
        }
        bool ok = true;
        for (int i=1; i<n; i++) {
            if (v[i] < v[i-1]) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}