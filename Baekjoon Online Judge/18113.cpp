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

ll n, k, m, v[1010101];

bool f(ll x) {
    ll cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += v[i] / x;
    }
    return cnt >= m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i] >= 2*k) v[i] -= 2*k;
        else if (v[i] > k) v[i] -= k;
        else v[i] = 0;
    }

    ll lo = 1;
    ll hi = 1e18;
    ll ans = -1;
    while (lo <= hi) {
        ll m = lo + (hi - lo) / 2;
        if (f(m)) {
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    cout << ans << '\n';
}