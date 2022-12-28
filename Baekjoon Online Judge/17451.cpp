#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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

ll n, v[303030];

bool f(ll m) {
    for (int i=0; i<n; i++) {
        if (m < v[i]) return false;
        m = m / v[i] * v[i];
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    ll lo = 1;
    ll hi = 1e18;
    ll ans = 0;
    while (lo <= hi) {
        ll m = lo + (hi - lo) / 2;
        if (f(m)) {
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    cout << ans << '\n';
}