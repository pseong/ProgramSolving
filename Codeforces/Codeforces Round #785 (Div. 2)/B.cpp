#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> sett(26, 0);
        for (int i=0; i<s.size(); i++) {
            sett[s[i]-'a'] = 1;
        }
        vector<int> idx[26];
        for (int i=0; i<s.size(); i++) {
            idx[s[i]-'a'].push_back(i);
        }
        bool fail = false;
        for (int i=0; i<26; i++) {
            if (fail) break;
            for (int j=1; j<idx[i].size(); j++) {
                vector<int> sett2(26, 0);
                for (int k=idx[i][j-1]; k<=idx[i][j]; k++) {
                    sett2[s[k]-'a'] = 1;
                }

                if (sett != sett2) {
                    fail = true;
                    break;
                }
            }
        }
        if (fail) cout << "NO\n";
        else cout << "YES\n";
    }
}