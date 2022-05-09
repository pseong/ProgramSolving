#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s; cin >> s;
        int cnt = 0;
        int get = 1;
        for (int i=1; i<n; i++) {
            if (s[i] != s[i-1]) {
                if (get%2 != 0) {
                    cnt++;
                    get = 1;
                }
            }
            get++;
        }
        cout << cnt << '\n';
    }
}