#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string I, P;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int i=1; i<=T; i++) {
        cin >> I >> P;
        if (P.size() < I.size()) {
            cout << "Case #" << i << ": " << "IMPOSSIBLE\n";
            continue;
        }
        else if (P.size() == I.size()) {
            if (P == I) {
                cout << "Case #" << i << ": " << "0\n";
                continue;
            }
        }
        int ans = 0;
        bool poss = true;
        int p = -1;
        for (int i=0; i<I.size(); i++) {
            p++;
            while (I[i] != P[p]) {
                p++;
                ans++;
                if (p >= P.size()) {
                    poss = false;
                    break;
                }
            }
            if (!poss) break;
        }
        ans += P.size()-1-p;
        if (!poss) cout << "Case #" << i << ": " << "IMPOSSIBLE\n";
        else {
            cout << "Case #" << i << ": " << ans << '\n';
        }
    }
}