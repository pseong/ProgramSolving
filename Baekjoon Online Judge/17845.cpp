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

    vector<vector<int>> dp(1010, vector<int>(10101));
    int n, t;
    cin >> t >> n;
    int mx = 0;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int k, s;
        cin >> s >> k;
        for (int j=0; j<=t; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-k >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-k] + s);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}