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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(2, vector<int>(n)), dp2(2, vector<int>(n));
    for (int i=1; i<n; i++) dp[0][i] = max(dp[0][i-1] + 1, v[0][i] + 1);
    dp[1][n-1] = max(dp[0][n-1] + 1, v[1][n-1] + 1);
    for (int i=n-2; i>=0; i--) dp[1][i] = max(dp[1][i+1] + 1, v[1][i] + 1);
    dp2[1][0] = v[1][0] + 1;
    for (int i=1; i<n; i++) dp2[1][i] = max(dp2[1][i-1] + 1, v[1][i] + 1);
    dp2[0][n-1] = max(dp2[1][n-1] + 1, v[0][n-1] + 1);
    for (int i=n-2; i>=0; i--) dp2[0][i] = max(dp2[0][i+1] + 1, v[0][i] + 1);

    int ans = 2020202020;
    int now = 0;
    for (int i=0; i<n; i+=2) {
        ans = min(ans, max(now + (n-1-i) * 2 + 1, dp[1][i]));
        now = max(now + 1, v[1][i] + 1);
        ans = min(ans, max(now + (n-1-i) * 2, dp2[0][i+1]));
        now = max(now + 1, v[1][i+1] + 1);
        now = max(now + 1, v[0][i+1] + 1);
        now = max(now + 1, v[0][i+2] + 1);
    }
    cout << ans << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}