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
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i=0; i<n; i++) {
            cin >> s[i];
        }
        int ans = 1e9;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int res = 0;
                for (int k=0; k<m; k++) {
                    res += abs(s[i][k]-s[j][k]);
                }
                ans = min(ans, res);
            }
        }
        cout << ans << '\n';
    }
}