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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int zero = count(v.begin(), v.end(), 0);
        if (zero) {
            cout << n-zero << '\n';
        }
        else {
            bool same = false;
            for (int i=1; i<n; i++) {
                if (v[i] == v[i-1]) same = true;
            }
            if (same) cout << n << '\n';
            else cout << n+1 << '\n';
        }
    }
}