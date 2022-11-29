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

int m, t;
int g[10101], w[10101], can[10101], dp[10101][2];
const int inf = 1e9;

void init(int x) {
    if (g[x] == -1) return;
    if (w[x*2] == -1) init(x*2);
    if (w[x*2+1] == -1) init(x*2+1);
    if (g[x] == 0) w[x] = (w[x*2] | w[x*2+1]);
    else w[x] = (w[x*2] & w[x*2+1]);
}

int f(int x, int v) {
    if (dp[x][v] != -1) return dp[x][v];
    if (w[x] == v) return dp[x][v] = 0;
    if (g[x] == -1) return dp[x][v] = inf;
    int ans = inf;
    if (g[x] == 0) {
        if (v == 1) ans = min({ans, f(x*2, 1), f(x*2+1, 1)});
        else ans = min(ans, f(x*2, 0) + f(x*2+1, 0));
    }
    else {
        if (v == 1) ans = min(ans, f(x*2, 1) + f(x*2+1, 1));
        else ans = min({ans, f(x*2, 0) + f(x*2+1, 0), f(x*2, 0) + f(x*2+1, 1), f(x*2, 1) + f(x*2+1, 0)});
    }

    if (can[x]) {
        if (g[x] == 1) {
            if (v == 1) ans = min({ans, f(x*2, 1) + 1, f(x*2+1, 1) + 1});
            else ans = min(ans, f(x*2, 0) + f(x*2+1, 0) + 1);
        }
        else {
            if (v == 1) ans = min(ans, f(x*2, 1) + f(x*2+1, 1) + 1);
            else ans = min({ans, f(x*2, 0) + f(x*2+1, 0) + 1, f(x*2, 0) + f(x*2+1, 1) + 1, f(x*2, 1) + f(x*2+1, 0) + 1});
        }
    }
    return dp[x][v] = ans;
}

void solve(int CASE) {
    cin >> m >> t;
    for (int i=1; i<=(m-1)/2; i++) {
        cin >> g[i] >> can[i];
    }
    for (int i=(m-1)/2+1; i<=m; i++) {
        cin >> w[i];
    }
    init(1);
    int ans = f(1, t);
    cout << "Case #" << CASE << ": ";
    if (ans == inf) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        memset(g, -1, sizeof g);
        memset(w, -1, sizeof w);
        memset(can, 0, sizeof can);
        memset(dp, -1, sizeof dp);
        solve(t);
    }
}