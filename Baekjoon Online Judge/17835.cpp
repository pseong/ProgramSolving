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


vector<pll> adj[101010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[v].push_back({u, c});
    }
    priority_queue<pll> q;
    const ll inf = 100000000000;
    vector<ll> dist(n + 1, inf);
    for (int i=0; i<k; i++) {
        int a; 
        cin >> a;
        q.push({0, a});
        dist[a] = 0;
    }
    while (q.size()) {
        auto [d, x] = q.top();
        d = -d;
        q.pop();
        if (dist[x] < d) continue;
        for (auto [y, w] : adj[x]) {
            if (dist[y] > d + w) {
                dist[y] = d + w;
                q.push({-(d + w), y});
            }
        }
    }
    ll mx = *max_element(dist.begin() + 1, dist.end());
    for (int i=1; i<=n; i++) {
        if (dist[i] == mx) {
            cout << i << ' ';
            break;
        }
    }
    cout << '\n' << mx;
}