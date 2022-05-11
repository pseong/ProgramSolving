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
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        vector<vector<int>> f(n, vector<int>(m, 0));
        vector<vector<int>> g(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
                f[i][j] = g[i][j] = a[i][j];
                if (i-1 >= 0 && j-1 >= 0) {
                    f[i][j] += f[i-1][j-1];
                }
                if (i-1 >= 0 && j+1 < m) {
                    g[i][j] += g[i-1][j+1];
                }
            }
        }
        for (int i=n-1; i>0; i--) {
            for (int j=0; j<m; j++) {
                if (j - 1 >= 0) f[i-1][j-1] = f[i][j];
                if (j + 1 < m) g[i-1][j+1] = g[i][j];
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ans = max(ans, f[i][j]+g[i][j]-a[i][j]);
            }
        }
        cout << ans << '\n';
    }
}