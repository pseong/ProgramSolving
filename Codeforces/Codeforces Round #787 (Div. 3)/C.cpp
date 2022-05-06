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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ans(n, 1);
        int z = 0;
        for (int i=0; i<n; i++) {
            if (z) ans[i] = 0;
            else if (s[i] == '0') z = 1;
        }
        z = 0;
        for (int i=n-1; i>=0; i--) {
            if (z) ans[i] = 0;
            else if (s[i] == '1') z = 1;
        }
        int res = 0;
        for (int x : ans) res += x;
        cout << res << '\n';
    }
}