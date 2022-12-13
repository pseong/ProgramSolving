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

ll dp[10101][550], v[10101];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<=n+1; i++) {
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        for (int j=0; j<=m; j++) {
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + v[i]);
            if (i + j <= n + 1) dp[i+j][0] = max(dp[i+j][0], dp[i][j]);
        }
    }
    cout << dp[n + 1][0] << '\n';
}