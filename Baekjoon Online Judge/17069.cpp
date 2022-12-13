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

ll v[50][50], dp[50][50][3];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=2; j<=n; j++) {
            if (v[i][j]) continue;
            dp[i][j][0] += dp[i][j-1][0];
            dp[i][j][0] += dp[i][j-1][1];
            if (!v[i-1][j] && !v[i][j-1]) {
                dp[i][j][1] += dp[i-1][j-1][0];
                dp[i][j][1] += dp[i-1][j-1][1];
                dp[i][j][1] += dp[i-1][j-1][2];
            }
            dp[i][j][2] += dp[i-1][j][1];
            dp[i][j][2] += dp[i-1][j][2];
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << '\n';
}