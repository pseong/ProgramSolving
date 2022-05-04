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
        int i = 0;
        int j = s.size()-1;
        int pre_i = -1;
        int pre_j = -1;
        int end = 0;
        bool ok = true;
        while (i < j) {
            if (s[i] != s[j]) {
                if (pre_i == -1) {
                    pre_i = i;
                    pre_j = j;
                    i++;
                }
                else if (end == 0) {
                    i = pre_i;
                    j = pre_j;
                    end = 1;
                    j--;
                }
                else {
                    ok = false;
                    break;
                }
            }
            else {
                i++;
                j--;
            }
        }
        if (!ok) cout << 2 << '\n';
        else if (pre_i == -1) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}