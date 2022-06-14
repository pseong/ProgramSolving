#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int a;
        cin >> a;
        int cnt = 0;
        for (int i=0; i<3; i++) {
            int b;
            cin >> b;
            if (b > a) cnt++;
        }
        cout << cnt << '\n';
    }
}