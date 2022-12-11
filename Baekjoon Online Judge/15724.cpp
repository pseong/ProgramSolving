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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = v[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << dp[x][y] + dp[a-1][b-1] - dp[x][b-1] - dp[a-1][y] << '\n';
    }
}