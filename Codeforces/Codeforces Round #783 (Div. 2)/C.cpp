#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int an[5050];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> an[i];
    }
    
    ll res = LONG_LONG_MAX;
    for (int p=0; p<n; p++) {
        ll ans = 0;
        ll prev = 0;
        for (int i=p-1; i>=0; i--) {
            if (prev == 0) {
                prev = an[i];
                ans++;
                continue;
            }
            ans += prev / an[i] + 1;
            prev = (prev / an[i] + 1) * an[i];
        }
        prev = 0;
        for (int i=p+1; i<n; i++) {
            if (prev == 0) {
                prev = an[i];
                ans++;
                continue;
            }
            ans += prev / an[i] + 1;
            prev = (prev / an[i] + 1) * an[i];
        }
        res = min(res, ans);
    }
    cout << res;
}