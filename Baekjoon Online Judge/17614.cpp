#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int cal(int n) {
    int ans = 0;
    while (n > 0) {
        if (n%10 == 3 || n%10 == 6 || n%10 == 9) ans++;
        n /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans += cal(i);
    }
    cout << ans;
}