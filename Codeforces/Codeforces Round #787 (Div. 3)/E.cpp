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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
 
        char mx = 'a';
        for (int i=0; i<s.size(); i++) {
            if (s[i]-'a' > k) break;
            mx = max(mx, s[i]);
        }
        int use = mx-'a';
        k -= use;
        for (int i=0; i<s.size(); i++) {
            if (s[i] <= 'a'+use) s[i] = 'a';
        }

        char c = 'a';   
        for (int i=0; i<s.size(); i++) {
            if (s[i]-'a' > k) {
                c = s[i];
                break;
            }
        }
        
        char reset = max('a', char(c-k));
        for (int i=0; i<s.size(); i++) {
            if (s[i] <= c && s[i] > reset) s[i] = reset;
        }
 
        cout << s << '\n';
    }
}
