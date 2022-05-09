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
        vector<int> v(n+1);
        for (int i=1; i<=n; i++) {
            cin >> v[i];
        }
        vector<int> f(n+1);
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (v[i] > v[j]) f[i]++;
            }
        }
        ll ans = 0;
        for (int k=1; k<=n; k++) {
            for (int i=1; i<k; i++) {
                if (v[i] > v[k]) f[i]--;
            }
            vector<ll> pref(n+1);
            for (int i=1; i<=n; i++) {
                pref[i] = pref[i-1] + f[i];
            }
            for (int i=1; i<k; i++) {
                if (v[i] < v[k]) {
                    ans += pref[k-1] - pref[i];
                }
            }
        }
        cout << ans << '\n';
    }
}