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

double dp[5050][5050];

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<double> ans(n + 1);
    vector<int> chk(n + 1);
    ans[n] = 1.0;
    chk[n] = 1;
    auto dfs = [&](auto self, int x) -> void {
        chk[x] = 1;
        for (int y : adj[x]) {
            if (chk[y]) continue;
            self(self, y);
        }
        sort(adj[x].begin(), adj[x].end(), [&](int a, int b) -> bool {
            return ans[a] > ans[b];
        });
        ans[x] = 0;
        int n = adj[x].size();
        for (int i=1; i<=n; i++) {
            ans[x] += dp[n][i] * ans[adj[x][i - 1]];
        }
    };
    dfs(dfs, 1);
    cout << fixed << setprecision(9) << ans[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    dp[1][1] = 1.0;
    for (int i=2; i<=5000; i++) {
        dp[i][1] = 1.0 / i;
        for (int j=2; j<=i; j++) {
            dp[i][j] = 1.0 * (j - 2) / i * dp[i - 2][j - 2] + 1.0 * (i - j) / i * dp[i - 2][j - 1];
        }
    }
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}