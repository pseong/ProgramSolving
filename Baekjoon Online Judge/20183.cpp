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

const ll inf = 1e15;
vector<pi> adj[101010];
ll n, m, a, b, c;

bool cal(ll p) {
    vector<ll> dist(n + 1, inf);
    priority_queue<pll> q;
    dist[a] = 0;
    q.push({0, a});
    while (q.size()) {
        auto [d, x] = q.top();
        d = -d;
        q.pop();
        if (dist[x] < d) continue;
        for (auto [y, w] : adj[x]) {
            if (w > p) continue;
            if (dist[y] > d + w) {
                dist[y] = d + w;
                q.push({-(d + w), y});
            }
        }
    }
    return dist[b] <= c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> a >> b >> c;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    ll lo = 1;
    ll hi = 1e14;
    ll ans = inf;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (cal(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}