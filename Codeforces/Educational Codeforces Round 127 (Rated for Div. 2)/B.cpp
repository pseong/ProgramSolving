#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int an[202020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        int go = an[0] + n-1;
        if (an[n-1] >= go-1 && an[n-1] <= go +1) {
            cout << "YES\n";
            continue;
        }
        go--;
        if (an[n-1] >= go-1 && an[n-1] <= go +1) {
            cout << "YES\n";
            continue;
        }
        go++;
        go++;
        if (an[n-1] >= go-1 && an[n-1] <= go +1) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}