#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int chk[101010];
int an[101010];
int bn[101010];
int cn[101010];
int go[101010];
const int mod = 1000000007;

ll powll(int x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    ll res = powll(x, y/2);
    res = res*res%mod;
    if (y%2 == 1) return res*x % mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) chk[i] = 0;
        for (int i=1; i<=n; i++) {
            cin >> an[i];
            go[an[i]] = i;
        }
        for (int i=1; i<=n; i++) cin >> bn[i];
        for (int i=1; i<=n; i++) {
            cin >> cn[i];
            if (an[i] == bn[i]) cn[i] = an[i];
        }

        int p = 0;
        for (int i=1; i<=n; i++) {
            if (chk[i] == 0) {
                int st = i;
                bool must = false;
                while (chk[st] == 0) {
                    if (cn[st] != 0) must = true;
                    chk[st] = 1;
                    st = go[bn[st]];
                }
                if (must == false) p++;
            }
        }
        cout << powll(2, p) << '\n';
    }
}