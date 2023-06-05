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

const int inf = 1e9;

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -inf));
    dp[1][0] = 1;
    for (int i=2; i<=n; i++) dp[i][1] = 1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<=n; j++) {
            if (v[i+1] > v[i]) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
            for (int t=i+2; t<=n; t++) {
                if (j+1 <= n && v[t] > v[i]) dp[t][j+1] = max(dp[t][j+1], dp[i][j] + 1);
            }
        }
    }
    for (int k=1; k<=n; k++) {
        int ans = inf;
        for (int i=1; i<=n; i++) {
            if (i < n)
                for (int j=0; j<=k-1; j++) {
                    ans = min(ans, n - dp[i][j]);
                }
            else if (i == n)
                for (int j=0; j<=k; j++) {
                    ans = min(ans, n - dp[i][j]);
                }
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}