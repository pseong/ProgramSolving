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
        int n; cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        bool ok = true;
        for (int i=2; i<n; i+=2) {
            if (v[i]%2 != v[i-2]%2) ok = false;
        }
        for (int i=3; i<n; i+=2) {
            if (v[i]%2 != v[i-2]%2) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}