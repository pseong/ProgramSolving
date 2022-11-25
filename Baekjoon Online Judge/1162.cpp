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

vector<pll> adj[10101];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    const ll inf = 1e15;
    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, inf));
    priority_queue<tll> q;
    dist[1][0] = 0;
    q.push({0, 1, 0});
    while (q.size()) {
        auto [d, a, b] = q.top();
        d = -d;
        q.pop();
        if (dist[a][b] < d) continue;
        for (auto [y, d2] : adj[a]) {
            if (dist[y][b] > d + d2) {
                dist[y][b] = d + d2;
                q.push({-(d + d2), y, b});
            }
            if (b + 1 <= k && dist[y][b + 1] > d) {
                dist[y][b + 1] = d;
                q.push({-d, y, b + 1});
            }
        }
    }
    ll ans = inf;
    for (int i=0; i<=k; i++) {
        ans = min(ans, dist[n][i]);
    }
    cout << ans << '\n';
}