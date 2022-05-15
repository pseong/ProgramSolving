#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int d=1; d<=n; d++) if (n%d == 0) {
        int res = n;
        for (int x=0; x<d; x++) {
            int cnt[26]{ 0 };
            for (int i=x; i<n; i+=d) {
                cnt[s[i]-'a']++;
            }
            int mx = 0;
            for (int i=0; i<26; i++) {
                mx = max(mx, cnt[i]);
            }
            res -= mx;
        }
        if (res <= k) {
            cout << d;
            break;
        }
    }
}
