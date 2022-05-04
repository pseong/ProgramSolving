#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n==1) {
        cout << 0;
        return 0;
    }
    int c[260]{ 0 };
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'B') c['B']++;
        else c['R']++;
    }
    int ans = min(c['R'], c['B']);
    for (int i=1; i<=s.size(); i++) {
        if (i == s.size()) {
            cout << 0;
            return 0;
        }
        if (s[i] != s[i-1]) {   
            ans = min(ans, c[s[0]]-i);
            break;
        }
    }
    for (int i=s.size()-2; i>=0; i--) {
        if (s[i] != s[i+1]) {
            ans = min(ans, c[s.back()]-n+i+1);
            break;
        }
    }
    cout << ans;
}