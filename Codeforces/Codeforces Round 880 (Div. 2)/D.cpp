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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    srt(v);
    ll posl = 0, posr = 0;
    auto cal = [&](ll x) -> ll {
        while (posl < n && v[posl] < x) posl++;
        while (posr < n && v[posr] <= x) posr++;
        ll l = posr < k ? 0 : (v[posr - k] + x) / 2 + 1;
        ll r = posl + k - 1 >= n ? m : (v[posl + k - 1] + x + 1) / 2 - 1;
        return max(0LL, r - l + 1);
    };
    vector<ll> ans { cal(0), 0 };
    for (int i=0; i<n; i++) {
        ll s = i == 0 ? max(0LL, v[i] - 2) : max(v[i - 1] + 3, v[i] - 2);
        ll e = min(m, v[i] + 2);
        for (ll x=s; x<=e; x++) {
            ll res = cal(x);
            if (res > ans[0]) {
                ans[0] = res;
                ans[1] = x;
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}