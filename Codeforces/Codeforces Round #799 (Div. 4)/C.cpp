#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        vector<string> s(8);
        for (int i=0; i<8; i++) {
            cin >> s[i];
        }
        for (int i=1; i<8; i++) {
            for (int j=1; j<8; j++) {
                if (s[i-1][j-1] == '#' && s[i-1][j+1] == '#' && s[i][j] == '#') {
                    cout << i+1 << ' ' << j+1 << '\n';
                }
            }
        }
    }
}