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

vector<int> adj[100];
ll dp[100][100];
int n, K;
const ll mod = 1000000007;

void dfs(int x, int parent) {
    bool f = true;
    for (int y : adj[x]) {
        if (y == parent) continue;
        dfs(y, x);
        vector<ll> v(K + 1);
        for (int k=2; k<=K; k++) {
            if (y == parent) continue;
            if (f) {
                dp[x][k] = dp[y][k-1];
                continue;
            }
            v[k] = dp[x][k];
            for (int p=1; p<=k-1; p++) {
                v[k] += dp[x][p] * dp[y][k-p];
                v[k] %= mod;
            }
        }
        if (!f) {
            for (int k=2; k<=K; k++) {
                dp[x][k] = v[k];
            }
        }
        f = false;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> K;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        dp[i][1] = 1;
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ans += dp[i][K];
        ans %= mod;
    }
    cout << ans << '\n';
}