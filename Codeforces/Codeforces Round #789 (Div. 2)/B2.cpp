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
        int prev = -1;
        int sec = 0;
        for (int i=0; i<n; i+=2) {
            if (s[i] != s[i+1]) cnt++;
            else {
                if (prev == -1) prev = s[i]-'0';
                else if (prev != s[i]-'0') {
                    sec++;
                    prev = s[i]-'0';
                }
            }
        }
        cout << cnt << ' ' << sec+1 << '\n';
    }
}