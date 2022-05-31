#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        if (s[n-1] == '0') {
            for (int i=n-2; i>=0; i--) {
                if (s[i] == '1' && n-1-i <= k) {
                     k -= n-1-i;
                     swap(s[n-1], s[i]);
                     break;
                }
            }
        }

        if (s[0] == '0') {
            for (int i=1; i<n-1; i++) {
                if (s[i] == '1' && i <= k) {
                    k -= i;
                    swap(s[0], s[i]);
                    break;
                }
            }
        }

        ll ans = 0;
        for (int i=0; i<n-1; i++) {
            if (s[i] == '0' && s[i+1] == '0') ans += 0;
            else if (s[i] == '0' && s[i+1] == '1') ans += 1;
            else if (s[i] == '1' && s[i+1] == '0') ans += 10;
            else if (s[i] == '1' && s[i+1] == '1') ans += 11;
        }
        cout << ans << '\n';
    }
}