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
        vector<int> w(n);
        for (int i=0; i<n; i++) {
            cin >> w[i];
        }
        int l = 0;
        int r = n-1;
        ll a = w[0];
        ll b = w[n-1];
        ll ans = 0;
        while (l < r) {
            if (a == b) {
                ans = n-r+l+1;
                l++; r--;
                a += w[l];
                b += w[r];
            }
            else if (a < b) {
                l++;
                a += w[l];
            }
            else if (a > b) {
                r--;
                b += w[r];
            }
        }
        cout << ans << '\n';
    }
}