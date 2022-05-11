#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        vector<int> prf(n);
        prf[0] = v[0];
        for (int i=1; i<n; i++) {
            prf[i] = prf[i-1] + v[i];
        }
        for (int i=0; i<q; i++) {
            int x; cin >> x;
            int idx = lower_bound(prf.begin(), prf.end(), x) - prf.begin();
            if (idx == n) cout << -1 << '\n';
            else cout << idx + 1 << '\n';
        }
    }
}