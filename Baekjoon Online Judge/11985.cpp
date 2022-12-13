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

ll dp[20202], v[20202];
const ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    fill(dp, dp + 20202, inf);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<=n; i++) {
        ll mn = v[i];
        ll mx = v[i];
        for (int cnt=1; cnt<=min(m, (ll)i); cnt++) {
            int j = i - cnt + 1;
            mn = min(mn, v[j]);
            mx = max(mx, v[j]);
            dp[i] = min(dp[i], k + cnt * (mx - mn) + dp[j-1]);
        }
    }
    cout << dp[n] << '\n';
}