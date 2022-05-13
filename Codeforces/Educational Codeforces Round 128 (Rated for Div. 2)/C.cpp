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
        string s; cin >> s;
        int n = s.size();
        int zero = 0;
        int one = 0;
        int all = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') all++;
        }
 
        int ans = all;
        int l = 0;
        int r = -1;
        while (l < n && r < n) {
            if (l >= r || zero < all-one) {
                r++;
                if (r == n) break;
                if (s[r] == '1') one++;
                else zero++;
            }
            else {
                if (s[l] == '1') one--;
                else zero--;
                l++;
            }
            ans = min(ans, max(zero, all-one));
        }
        cout << ans << '\n';
    }
}