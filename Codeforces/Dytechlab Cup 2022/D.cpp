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

vector<pll> adj[550];

const ll inf = 1e18;

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) adj[i].clear();
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, inf));
    vector<tll> p;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        p.push_back({a, b, c});
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int i=1; i<=n; i++) dist[i][i] = 0;
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = 1e18;
    for (auto [a, b, c] : p) {
        ans = min(ans, (dist[a][1] + dist[b][n] + 1) * c);
        ans = min(ans, (dist[a][n] + dist[b][1] + 1) * c);
        for (int i=1; i<=n; i++) {
            ans = min(ans, (dist[a][i] + dist[i][1] + dist[i][n] + 2) * c);
            ans = min(ans, (dist[b][i] + dist[i][1] + dist[i][n] + 2) * c);
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