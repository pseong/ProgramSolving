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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        for (int i=(1<<30); i>=1; i>>=1) {
            int cnt = 0;
            for (int x=0; x<v.size(); x++) {
                if ((v[x]&i) == 0) cnt++;
            }
            if (cnt <= k) {
                k -= cnt;
                for (int x=0; x<v.size(); x++) {
                    v[x] |= i;
                }
            }
        }
        int ans = v[0];
        for (int i=1; i<v.size(); i++) {
            ans &= v[i];
        }
        cout << ans << '\n';
    }
}