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
        int an[30]{ 0 };
        int bn[30]{ 0 };
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        for (int i=0; i<n; i++) {
            cin >> bn[i];
        }
        ll ans = 0;
        for (int i=1; i<n; i++) {
            int l = min(an[i], bn[i]);
            int r = max(an[i], bn[i]);

            
            int s = min(an[i-1], bn[i-1]);
            int e = max(an[i-1], bn[i-1]);

            ans += min(abs(e-r)+abs(s-l), abs(e-l)+abs(s-r));
        }
        cout << ans << '\n';
    }
}