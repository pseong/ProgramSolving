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
        string s;
        cin >> s;
        bool fail = false;
        for (int i=1; i<(s.size()-1); i++) {
            if (s[i] != s[i+1] && s[i] != s[i-1]) {
                fail = true;
            }
        }
        if (s[0] != s[1]) fail = true;
        if (s[s.size()-1] != s[s.size()-2]) fail = true;
        if (fail) cout << "NO\n";
        else cout << "YES\n";
    }
}