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

ll dp[330][330][110];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for (int l=1; l<=n; l++) {
        int x, y;
        cin >> x >> y;
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=k; j++) {
                dp[i][j][l] = dp[i][j][l-1];
                if (i >= x && j >= y) dp[i][j][l] = max(dp[i][j][l-1], dp[i-x][j-y][l-1] + 1);
                ans = max(ans, dp[i][j][l]);
            }
        }
    }
    cout << ans << '\n';
}