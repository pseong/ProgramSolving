#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int left = 0;
    int ans = 0;
    if(m*2 <= n) {
        ans = m;
        left = n-2*ans;
    } else {
        ans = n/2;
        left = m + n - 3*ans;
    }

    k -= left;
    if(k > 0) ans -= ((k+2)/3);

    cout << max(0, ans);
}