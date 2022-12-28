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

int v[1010][1010], dp[1010][1010][3];
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=1; i<1010; i++) {
        for (int j=0; j<1010; j++) {
            for (int k=0; k<3; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (j + 1 <= m) dp[i][j][0] = min(dp[i][j][0], min(dp[i-1][j+1][1], dp[i-1][j+1][2]) + v[i][j]);
            if (j - 1 >= 0) dp[i][j][2] = min(dp[i][j][2], min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + v[i][j]);
            dp[i][j][1] = min(dp[i][j][1], min(dp[i-1][j][0], dp[i-1][j][2]) + v[i][j]);
        }
    }
    int ans = inf;
    for (int j=1; j<=m; j++) {
        for (int k=0; k<3; k++) {
            ans = min(ans, dp[n][j][k]);
        }
    }
    cout << ans << '\n';
}