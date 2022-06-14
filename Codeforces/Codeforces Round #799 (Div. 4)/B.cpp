#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> m;
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            m[a]++;
        }
        int ans = 0;
        int e = 0;
        for (auto a : m) {
            if (a.second%2) ans++;
            else e++;
        }
        if (e % 2 == 1) e--;
        cout << ans + e << '\n';
    }
}