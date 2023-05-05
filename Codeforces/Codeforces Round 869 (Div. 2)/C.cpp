#include <bits/stdc++.h>
using namespace std;
using pi=pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    vector<int> cnt(n + 1);
    for (int i=2; i<n; i++) {
        if (v[i] <= v[i-1] && v[i] >= v[i+1]) cnt[i]++;
    }
    for (int i=1; i<=n; i++) cnt[i] += cnt[i-1];
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 1 << '\n';
            continue;
        }
        cout << b - a + 1 - (cnt[b-1] - cnt[a]) << '\n';
    }
}