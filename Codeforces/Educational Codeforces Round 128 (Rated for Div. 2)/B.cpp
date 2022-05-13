#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        string s[10];
        for (int i=0; i<n; i++) cin >> s[i];
        int fa = -1;
        int fb = -1;
        int sa = -1;
        int sb = -1;
        for (int j=0; j<m; j++) {
            for (int i=0; i<n; i++) {
                if (s[i][j] == 'R' && fa == -1) {
                    fa = i;
                    fb = j;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (s[i][j] == 'R' && sa == -1) {
                    sa = i;
                    sb = j;
                }
            }
        }
        if (fa == sa || fb == sb) cout << "YES\n";
        else cout << "NO\n";
    }
}