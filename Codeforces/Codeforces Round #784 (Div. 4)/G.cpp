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
        int n, m;
        cin >> n >> m;
        string s[n];
        for (int i=0; i<n; i++) {
            cin >> s[i];
        }
        for (int i=n-2; i>=0; i--) {
            for (int a=i; a<n-1; a++) {
                for (int b=0; b<m; b++) {
                    if (s[a][b] == '*' && s[a+1][b] == '.') {
                        s[a][b] = '.';
                        s[a+1][b] = '*';
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            cout << s[i] << '\n';
        }
        cout << '\n';
    }
}