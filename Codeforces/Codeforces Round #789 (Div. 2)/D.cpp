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
        int n, m; cin >> n >> m;
        vector<int> col(m), row(m);
        string s; cin >> s;
        int last = -1000000;
        int coln = 0;
        for (int i=0; i<n*m; i++) {
            if (s[i] == '1') {
                last = i;
                if (col[i%m] == 0) {
                    coln++;
                    col[i%m] = 1;
                }
            }
            if (i - last < m) {
                row[i%m]++;
            }
            cout << coln + row[i%m] << ' ';
        }
        cout << '\n';
    }
}