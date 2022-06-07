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
        int n; cin >> n;
        vector<int> v(n), v2(n);
        for (int i=0; i<n; i++) cin >> v[i];
        for (int i=0; i<n; i++) cin >> v2[i];
        
        int m = 0;
        bool ok = true;
        for (int i=0; i<n; i++) {
            int p = v[i] - m;
            if (p < 0) p = 0;
            if (p < v2[i]) {
                ok = false;
            }
            else if (p > v2[i]) {
                m += p-v2[i];
                i = -1;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}