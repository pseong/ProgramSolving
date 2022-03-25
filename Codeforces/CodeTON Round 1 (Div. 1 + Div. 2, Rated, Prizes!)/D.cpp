#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll pow = 1;
        while (!(n&1)) {
            n >>= 1;
            pow += 1;
        }
        if (n==1) {
            cout << -1 << '\n';
            continue;
        }
        ll k = 1ll << pow;
        if (k < n) {
            cout << k << '\n';
            continue;
        }
        else {
            cout << n << '\n';
            continue;
        }
    }
}