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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    if (s == s2) {
        cout << 0 << '\n';
        return;
    }
    cout << 1 << '\n';
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (s[i] != s2[i]) {
            v.push_back(i);
        }
    }
    cout << v.size() << ' ';
    for (int x : v) {
        cout << x+1 << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}