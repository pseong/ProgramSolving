#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

ll hn[303];
ll gap[303];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
/*
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll mx = 0;
        for (int i=0; i<n; i++) {
            cin >> hn[i];
            mx = max(mx, hn[i]);
        }
        for (int i=0; i<n; i++) {
            gap[i] = mx-hn[i];
        }

        int idx = 0;
        ll ans = 0;
        bool fail = false;
        for (int i=0; i<n; i++) {
            if (gap[i] & 1) {
                while (idx < n && gap[idx] < 2) idx++;
                if (idx == n) {
                    fail = true;
                    break;
                }
                gap[idx] -= 2;
                gap[i] -= 1;
                ans += 2;
            }
        }
        if (fail) {
            ll one = 0;
            ll two = 0;
            ll f = 0;
            for (int i=0; i<n; i++) {
                if (gap[i] == 1) {
                    one++;
                }
            }
            ans += one*2-1;
        }
        else {
            ll sum = 0;
            for (int i=0; i<n; i++) {
                sum += gap[i];
            }
            ans += sum/3*2;
            sum -= sum/3*3;
            ans += sum;
        }
        cout << ans << '\n';
    }
*/
}