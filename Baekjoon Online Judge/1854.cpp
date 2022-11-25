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

vector<pll> adj[1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<vector<ll>> dist(n + 1, vector<ll>());
    priority_queue<pll> q;
    q.push({0, 1});
    while (q.size()) {
        auto [d, x] = q.top();
        d = -d;
        q.pop();
        if (dist[x].size() == k) continue;
        dist[x].push_back(d);
        for (auto [y, d2] : adj[x]) {
            if (dist[y].size() == k) continue;
            q.push({-(d + d2), y});
        }
    }
    for (int i=1; i<=n; i++) {
        if (dist[i].size() < k) cout << -1 << '\n';
        else cout << dist[i][k-1] << '\n';
    }
}