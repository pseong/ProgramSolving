#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s[2020];
        for (int i=0; i<n; i++) {
            cin >> s[i];
        }
        int cnt[2020]{ 0 };
        for (int d=0; d<n; d++) {
            for (int i=d, j=0; i<d+n; i++, j++) {
                int _i = i%n;
                if (s[_i][j] == '1') cnt[d]++;
            }
        }
        int ans = n*n;

        int res = 0;
        res += n-cnt[0];
        for (int i=1; i<n; i++) {
            res += cnt[i];
        }
        ans = min(ans, res);
        for (int d=1; d<n; d++) {
            res -= n-cnt[d-1];
            res += cnt[d-1];
            res -= cnt[d];
            res += n-cnt[d];
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}