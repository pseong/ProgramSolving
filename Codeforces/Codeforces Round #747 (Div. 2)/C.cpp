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
    int n; char c;
    cin >> n >> c;
    string s; cin >> s;
    s.insert(s.begin(), ' ');
    int error = 0;
    for (int i=1; i<=n; i++) {
        if (s[i] != c) error++;
    }
    if (error == 0) {
        cout << 0 << '\n';
        return;
    }
    int idx = 0;
    for (int i=n; i>=1; i--) {
        if (s[i] == c) {
            idx = i;
            break;
        }
    }
    if (idx*2 <= n) {
        cout << 2 << '\n';
        cout << n << ' ' << n-1 << '\n';
    }
    else {
        cout << 1 << '\n';
        cout << idx << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}