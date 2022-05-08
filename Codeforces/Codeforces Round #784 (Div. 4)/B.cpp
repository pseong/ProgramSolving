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
        vector<int> cnt(n+1, 0);
        int ans = -1;
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            cnt[a]++;
            if (cnt[a] >= 3) ans = a;
        }
        cout << ans << '\n';
    }
}