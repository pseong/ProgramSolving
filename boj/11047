#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[11]{ 0 };
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = n; i >= 1; i--) {
        if(k / a[i] >= 0) {
            ans += k / a[i];
            k %= a[i];
        }
        if(k == 0) break;
    }
    cout << ans;
}