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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        for (int i=n-2; i>=0; i--) {
            if (v[i+1] == 0) {
                ans = -1;
                break;
            }
            while (v[i] >= v[i+1]) {
                ans++;
                v[i] /= 2;
            }
        }
        cout << ans << '\n';
    }
}