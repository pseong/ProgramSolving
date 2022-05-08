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
        ll cnt[12][12]{ 0 };
        memset(cnt, 0, sizeof cnt);
        int n; cin >> n;
        ll ans = 0;
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            cnt[s[0]-'a'][s[1]-'a']++;
            for (int k=0; k<12; k++) {
                if (k == s[0]-'a') continue;
                ans += cnt[k][s[1]-'a'];
            }
            for (int k=0; k<12; k++) {
                if (k == s[1]-'a') continue;
                ans += cnt[s[0]-'a'][k];
            }
        }
        cout << ans << '\n';
    }
}