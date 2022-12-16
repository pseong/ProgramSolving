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

int n, m;
int dp[10101][150], chk[10101];
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    fill(&dp[0][0], &dp[10100][150], inf);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        chk[a] = 1;
    }
    dp[1][0] = 0;
    for (int i=1; i<=n; i++) {
        if (chk[i]) continue;
        for (int j=0; j<=150; j++) {
            if (i+j+1 <= n) dp[i+j+1][j+1] = min(dp[i+j+1][j+1], dp[i][j] + 1);
            if (i+j <= n && j >= 1) dp[i+j][j] = min(dp[i+j][j], dp[i][j] + 1);
            if (i+j-1 <= n && j-1 >= 1) dp[i+j-1][j-1] = min(dp[i+j-1][j-1], dp[i][j] + 1);
        }
    }
    int ans = inf;
    for (int i=0; i<=150; i++) {
        ans = min(ans, dp[n][i]);
    }
    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}