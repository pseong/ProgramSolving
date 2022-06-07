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
        int w = 0;
        for (int i=0; i<k; i++) {
            if (s[i] == 'W') w++;
        }
        int ans = w;
        for (int i=k; i<n; i++) {
            if (s[i] == 'W') w++;
            if (s[i-k] == 'W') w--;
            ans = min(ans, w);
        }
        cout << ans << '\n';
    }
}