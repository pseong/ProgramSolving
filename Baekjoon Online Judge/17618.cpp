#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int cal(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n%10;
        n /=10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (i % cal(i) == 0) ans++;
    }
    cout << ans;
}