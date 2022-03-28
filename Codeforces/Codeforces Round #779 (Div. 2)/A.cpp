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
        string s;
        cin >> s;
        int ans = 0;
        int last = -10;
        for (int i=0; i<n; i++) {
            if (s[i] == '0') {
                int diff = i-last;
                ans += max(0, 3-diff);
                last = i;
            }
        }
        cout << ans << '\n';
    }
}