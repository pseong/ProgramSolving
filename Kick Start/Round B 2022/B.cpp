#include <bits/stdc++.h>
using namespace std;
using ll=long long;

unordered_map<ll, bool> dp;
bool pal(ll n) {
    if (n>10 && dp[n-1]) return false;
    string s = to_string(n);
    int i = 0;
    int j = s.size()-1;
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        else return false;
    }
    return dp[n] = true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        ll a;
        cin >> a;
        ll ans = 0;
        for (int i=1; i*i<=a; i++) {
            if (a%i == 0) {
                if (a == i*i) {
                    if (pal(i)) ans++;
                }
                else {
                    if (pal(i)) ans++;
                    if (pal(a/i)) ans++;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}