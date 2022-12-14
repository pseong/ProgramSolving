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

ll dp[110][101010], v[110][4];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
    }
    const ll inf = 1e18;
    fill(&dp[0][0], &dp[109][101010], -inf);
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            if (j-v[i][0] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-v[i][0]] + v[i][1]);
            if (j-v[i][2] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-v[i][2]] + v[i][3]);
        }
    }
    ll ans = 0;
    for (int i=0; i<=k; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << '\n';
}