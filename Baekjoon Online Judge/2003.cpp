#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    int r = -1;
    int sum = 0;
    for (int l=0; l<n; l++) {
        while (r < n && sum < m) r++, sum += v[r];
        if (sum == m) ans++;
        sum -= v[l];
    }
    cout << ans << '\n';
}