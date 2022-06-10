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
        vector<int> v(n), ans(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        if (n == 1) {
            cout << -1 << '\n';
            continue;
        }
        for (int i=0; i<n; i++) {
            ans[i] = i+1;
        }
        for (int i=0; i<n-1; i++) {
            if (v[i] == ans[i]) {
                swap(ans[i], ans[i+1]);
            }
        }
        if (v[n-1] == ans[n-1]) {
            swap(ans[n-2], ans[n-1]);
        }
        for (int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}