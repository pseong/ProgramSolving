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
        string s; cin >> s;
        int sum = 0;
        for (int i=0; i<3; i++) {
            sum += s[i];
        }
        for (int i=3; i<6; i++) {
            sum -= s[i];
        }
        if (sum ==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}