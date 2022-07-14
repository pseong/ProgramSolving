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

ll n, m, p;

ll dp[110][110];

ll f(int i, int cnt) {
    if (dp[i][cnt] != -1) return dp[i][cnt];
    if (i == p) {
        if (cnt == n) return 1;
        else return 0;
    }
    ll ans = 0;
    if (cnt < n) ans += f(i+1, cnt+1) * (n - cnt);
    if (cnt > m) ans += f(i+1, cnt) * (cnt - m);
    return dp[i][cnt] = ans % 1000000007;
}

void solve() {
    cin >> n >> m >> p;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << '\n';   
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}