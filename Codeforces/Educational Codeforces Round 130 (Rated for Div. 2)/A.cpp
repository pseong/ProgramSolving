#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vll v(n+1), pref(n+1);
        for (int i=1; i<=n; i++) {
            cin >> v[i];
            pref[i] = pref[i-1] + v[i];
        }
        auto it = upper_bound(pref.begin(), pref.end(), m);
        if (it == pref.end()) {
            cout << 0 << '\n';
        }
        else {
            cout << pref.back() - m << '\n';
        }
    }
}