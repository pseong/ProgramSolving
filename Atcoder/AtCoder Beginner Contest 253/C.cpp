#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> mp;
    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int what; cin >> what;
        if (what == 1) {
            int x; cin >> x;
            mp[x]++;
        }
        else if (what == 2) {
            int x, c; cin >> x >> c;
            mp[x] -= c;
            if (mp[x] <= 0) {
                mp.erase(x);
            }
        }
        else {
            cout << mp.rbegin()->first - mp.begin()->first << '\n';
        }
    }
}