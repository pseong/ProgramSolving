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
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    if (n % 2) {
        cout << "Mike\n";
        return;
    }
    int pos = 0;
    for (int i=1; i<n; i++) {
        if (v[i] < v[pos]) pos = i;
    }
    if (pos%2 == 0) {
        cout << "Joe\n";
    }
    else {
        cout << "Mike\n";
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