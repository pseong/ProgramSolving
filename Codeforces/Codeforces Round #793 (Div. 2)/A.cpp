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
        int n; cin >> n;
        string s; cin >> s;
        int l, r;
        if (s.size() % 2 == 0) {
            l = s.size()/2-1;
            r = s.size()/2;
        }
        else {
            l = s.size()/2-1;
            r = s.size()/2+1;
        }
        while (l >= 0 && r < s.size() && s[l+1] == s[l] && s[r] == s[r-1]) {
            l--;
            r++;
        }
        r--;
        l++;
        cout << r-l+1 << '\n';
    }
}