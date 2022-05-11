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
        int n; cin >> n;
        vector<int> an(n);
        for (int i=0; i<n; i++) cin >> an[i];
        int mn = *min_element(an.begin(), an.end());
        int ans = 0;
        for (int i=0; i<n; i++) ans += an[i]-mn;
        cout << ans << '\n';
    }
    return 0;
}