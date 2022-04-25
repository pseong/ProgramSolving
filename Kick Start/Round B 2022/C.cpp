#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int n, d;
        cin >> n >> d;
        string s;
        for (int i=0; i<n; i++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        int i=-1;
        int j=s.size();
        for (int k=0; k<s.size(); k++) {
            if (s[k] == '1') {
                i = k;
                break;
            }
        }
        for (int k=(s.size()-1); k>=0; k--) {
            if (s[k] == '1') {
                j = k;
                break;
            }
        }
        if (i==-1) {
            cout << "Case #" << t << ": " << 0 << '\n';
            continue;
        }

        int ans = 1;
        char go = '1';
        while (true) {
            for (; i<j; i++) {
                if (s[i] == go) break;
            }
            for (; j>i; j--) {
                if (s[j] == go) break;
            }
            go ^= '0'^'1';
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}