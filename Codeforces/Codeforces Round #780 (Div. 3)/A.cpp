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
        int a, b;
        cin >> a >> b;
        if (a > 0) {
            cout << b*2 + a + 1 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }
}