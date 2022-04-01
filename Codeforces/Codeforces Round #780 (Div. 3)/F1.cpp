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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i=0; i<n; i++) {
            int card = 0;
            int cntP = 0;
            int cntM = 0;
            int chk[202020]{ 0 };
            for (int k=i; k<n; k++) {
                if (s[k] == '-') {
                    cntM++;
                    if (k-1>=i && !chk[k-1] && s[k-1] == '-') {
                        chk[k] = chk[k-1] = 1;
                        card++;
                    }
                }
                else cntP++;
                if (cntP == cntM) ans++;
                else if (cntP < cntM) {
                    int diff = cntM - cntP;
                    if (diff % 3 == 0) {
                        if (card >= diff/3 && cntM >= diff/3*2) ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}