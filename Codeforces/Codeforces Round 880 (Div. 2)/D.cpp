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

ll n, m, k;
vector<ll> v;
ll posl, posr;

ll cal(ll x) {
    while (posl < n && v[posl] < x) posl++;
    while (posr < n && v[posr] <= x) posr++;
    ll l = posr < k ? 0 : (x + v[posr - k]) / 2 + 1;
    ll r = posl + k - 1 >= n ? m : (v[posl + k - 1] + x - 1) / 2;
    return max(0LL, r - l + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    v.assign(n, 0);
    for (int i=0; i<n; i++) cin >> v[i];
    srt(v);
    ll res = cal(0), best = 0;
    for (int i=0; i<n; i++) {
        ll posz = i == 0 ? max(0LL, v[i] - 2) : max(v[i] - 2, v[i-1] + 3);
        ll kon = min(m, v[i] + 2);
        for (ll s=posz; s<=kon; s++) {
            ll ile = cal(s);
            if (ile > res) {
                res = ile;
                best = s;
            }
        }
    }
    cout << res << ' ' << best << '\n';
}