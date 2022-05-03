#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

ll powll(int a, int b) {
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2 == 0) {
        ll r = powll(a, b/2);
        return r*r;
    }
    else return a * powll(a, b-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int a = 0;
        for (int i=0; i<t.size(); i++) {
            if (t[i] == 'a') a++;
        }
        if (a == 0) {
            cout << (1ll << s.size()) << '\n';
        }
        else if (t.size() == 1) {
            cout << 1 << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}