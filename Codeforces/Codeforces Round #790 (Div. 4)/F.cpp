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
        int n, k; cin >> n >> k;
        vector<int> an(n);
        map<int, int> m;
        for (int i=0; i<n; i++) {
            cin >> an[i];
            m[an[i]]++;
        }
        int l = -1;
        int r = -1;
        int s = -1;
        int e = -1;
        for (auto [x, c] : m) {
            if (c < k) continue;
            if (x-1 != e) s = x;
            e = x;
            if (l == -1 || e-s > r-l) {
                l = s;
                r = e;
            }
        }
        if (l == -1) cout << -1 << '\n';
        else cout << l << ' ' << r << '\n';
    }
}
