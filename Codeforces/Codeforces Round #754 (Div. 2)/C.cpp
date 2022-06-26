#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

const int inf = 1000000000;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (s.find("aa") != string::npos) {
        cout << 2 << '\n';
    }
    else if (s.find("aba") != string::npos || s.find("aca") != string::npos) {
        cout << 3 << '\n';
    }
    else if (s.find("abca") != string::npos || s.find("acba") != string::npos) {
        cout << 4 << '\n';
    }
    else if (s.find("abbacca") != string::npos || s.find("accabba") != string::npos) {
        cout << 7 << '\n';
    }
    else cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}