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
        if (s.size() == 2) {
            cout << s.back() << '\n';
        }
        else {
            cout << *min_element(s.begin(), s.end()) << '\n';
        }
    }
}