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

const ll mod = 998244353;

ll cal(ll l, ll r) {
    ll cnt = 0;
    ll x = l;
    while (x <= r) {
        cnt++;
        x *= 2;
    }
    return cnt;
}

void solve(int CASE) {
    ll l, r;
    cin >> l >> r;
    ll cnt = cal(l, r);
    ll ans = r / (1LL << (cnt - 1)) - l + 1;
    ans %= mod;
    if (cnt > 1) {
        ans += max(0LL, (r / ((1LL << (cnt - 2)) * 3) - l + 1)) * (cnt - 1) % mod;
        ans %= mod;
    }
    cout << cnt << ' ' << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}