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

ll dp[110][110], v[110];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<110; i++) {
        for (int j=0; j<110; j++) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    ll ans = -1e9;
    for (int i=1; i<=n; i++) {
        dp[i][1] = v[i];
        for (int k=1; k<=m; k++) {
            if (dp[i-1][k] != -1e9) dp[i][k] = max(dp[i][k], dp[i-1][k] + v[i]);
        }
        for (int j=1; j<=i-2; j++) {
            for (int k=1; k<=m; k++) {
                if (dp[j][k-1] != -1e9) dp[i][k] = max(dp[i][k], dp[j][k-1] + v[i]);
            }
        }
        ans = max(ans, dp[i][m]);
    }
    cout << ans << '\n';
}