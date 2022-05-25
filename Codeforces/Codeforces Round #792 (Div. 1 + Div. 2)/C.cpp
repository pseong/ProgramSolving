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
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> v[i][j];
            }
        }
        auto v2 = v;
        for (int i=0; i<n; i++) {
            sort(v2[i].begin(), v2[i].end());
        }
        int a = -1;
        int b = -1;
        for (int i=0; i<n; i++) {
            vector<int> diff;
            for (int j=0; j<m; j++) {
                if (v[i][j] != v2[i][j]) {
                    diff.push_back(j);
                }
            }
            if (diff.size() == 0) continue;
            sort(diff.begin(), diff.end());
            a = diff.front();
            b = diff.back();
        }

        bool ok = true;
        for (int i=0; i<n; i++) {
            if (a != -1) swap(v[i][a], v[i][b]);
            if (v[i] != v2[i]) ok = false;
        }
        
        if (!ok) cout << -1 << '\n';
        else {
            if (a == -1) {
                cout << 1 << ' ' << 1 << '\n';
            }
            else {
                cout << a+1 << ' ' << b+1 << '\n';
            }
        }
    }
}