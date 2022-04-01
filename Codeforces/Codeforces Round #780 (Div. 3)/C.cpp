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
        string s;
        cin >> s;
        int ans = 0;
        int cnt[26]{ 0 };
        int start = 0;
        for (int i=0; i<(int)s.size(); i++) {
            if (cnt[s[i]-'a']) {
                ans += i-start-1;
                start = i+1;
                for (int j=0; j<26; j++) {
                    cnt[j] = 0;
                }
            }
            else {
                cnt[s[i]-'a']++;
            }
        }
        if (start != (int)s.size()) {
            ans += (int)s.size()-start;
        }
        cout << ans << '\n';
    }
}