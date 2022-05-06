#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int chk[30];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> s >> k;
        for (int i=0; i<26; i++) chk[i] = 0;
        for (int i=0; i<k; i++) {
            char a; cin >> a;
            chk[a-'a'] = true;
        }
        int prev = 0;
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (chk[s[i]-'a']) {
                ans = max(ans, i-prev);
                prev = i;
            }
        }
        cout << ans << '\n';
    }
}