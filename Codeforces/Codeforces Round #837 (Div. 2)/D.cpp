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
 
int n;
string s;
int dp[2020][2020], go[2020][2020];
vector<int> adj[2020];
vector<pi> k[2020];
 
void dfs(int v, int x, int len, int g, int p) {
    if (len == 1) g = x;
    k[len].push_back({v, x});
    go[v][x] = g;
    for (int y : adj[x]) {
        if (y == p) continue;
        dfs(v, y, len+1, g, x);
    }
}
 
void solve(int CASE) {
    cin >> n >> s;
    for (int i=1; i<=n; i++) {
        k[i].clear();
        adj[i].clear();
        for (int j=1; j<=n; j++) {
            dp[i][j] = 0;
            go[i][j] = 0;
        }
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) dfs(i, i, 0, 0, 0);
    for (int len=0; len<n; len++) {
        for (auto& [x, y] : k[len]) {
            if (len == 0) dp[x][y] = 1;
            else if (len == 1) dp[x][y] = 1 + (s[x-1] == s[y-1]);
            else dp[x][y] = max({dp[go[x][y]][y], dp[x][go[y][x]], dp[go[x][y]][go[y][x]] + 2 * (s[x-1] == s[y-1])});
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
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