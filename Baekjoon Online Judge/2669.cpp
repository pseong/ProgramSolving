#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int mp[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0; i<4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i=b; i<d; i++) {
            for (int j=a; j<c; j++) {
                mp[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=99; i++) {
        for (int j=1; j<=99; j++) {
            if (mp[i][j]) ans++;
        }
    }
    cout << ans;
}