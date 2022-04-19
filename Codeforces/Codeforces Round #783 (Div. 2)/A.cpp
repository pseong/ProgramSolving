#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        n--; m--;
        int add = 0;
        int gap = abs(n-m);
        if (gap >= 2 && (n == 0 || m == 0)) {
            cout << -1 << '\n';
            continue;
        }
        if (gap % 2 == 0) {
            add += gap;
        }
        else {
            add += gap - 1;
        }
        cout << n + m + add << '\n';
    }
}