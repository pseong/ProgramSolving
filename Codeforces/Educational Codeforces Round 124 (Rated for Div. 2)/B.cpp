#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n > 19) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            ll go = 1;
            for (int i=0; i<n; i++) {
                cout << go << ' ';
                go *= 3;
            }
            cout << '\n';
        }
    }
}