#include <bits/stdc++.h>
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

int dx[] {1, 0};
int dy[] {0, 1};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(m+1, 0));
    vector<vector<pi>> dp(n+1, vector<pi>(m+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        dp[i][1] = { dp[i-1][1].first + v[i][1], dp[i-1][1].second + v[i][1] };
    }
    for (int j=1; j<=m; j++) {
        dp[1][j] = { dp[1][j-1].first + v[1][j], dp[1][j-1].second + v[1][j] };
    }
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            pi up = { dp[i-1][j].first, dp[i-1][j].second };
            pi left = { dp[i][j-1].first, dp[i][j-1].second };
            dp[i][j] = { min(up.first, left.first) + v[i][j], max(up.second, left.second) + v[i][j]};
        }
    }
    if (dp[n][m].first <= 0 && dp[n][m].second >= 0 && (dp[n][m].first%2 == 0)) {
        yes();
    }
    else no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}