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
    vector<vector<int>> v(n+1, vector<int>(m+1));
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=m; j++) {
            v[i][j] = s[j-1] - '0';
        }
    } 
    vector<vector<int>> rdp(n+1, vector<int>(m+1)), ddp(n+1, vector<int>(m+1)), dp(n+1, vector<int>(m+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (v[i][j] == 1) rdp[i][j] = rdp[i][j-1] + 1;
        }
    }
    for (int j=1; j<=m; j++) {
        for (int i=1; i<=n; i++) {
            if (v[i][j] == 1) ddp[i][j] = ddp[i-1][j] + 1;
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = min({dp[i-1][j-1] + 1, rdp[i][j], ddp[i][j]});
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans << '\n';
}