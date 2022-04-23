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
        int n, x;
        cin >> n >> x;
        vector<int> an(n, 0);
        int mn = INT_MAX;
        int mx = INT_MIN;
        ll sum = 0;
        for (int i=0; i<n; i++) {
            cin >> an[i];
            mn = min(an[i], mn);
            mx = max(an[i], mx);
            if (i != 0) sum += abs(an[i]-an[i-1]);
        }

        if (mn > 1) {
            sum += mn-1 + min({mn-1, abs(an[0]-mn), abs(an[n-1]-mn)});
        }
        if (mx < x) {
            sum += x-mx + min({x-mx, abs(an[0]-mx), abs(an[n-1]-mx)});
        }
        cout << sum << '\n';
    }
}