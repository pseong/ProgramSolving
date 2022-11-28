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

vector<pi> adj[202020];
vector<vector<pi>> hist, g;
priority_queue<pi> q;
vector<int> dist;
int dis[202020];
const int inf = 1e9;
int n, m;

int da(int s, int e) {
    dist.assign(n + 1, inf);
    hist.assign(n + 1, vector<pi>());
    g.assign(n + 1, vector<pi>());
    dist[s] = 0;
    q.push({0, s});
    while (q.size()) {
        auto [d, x] = q.top();
        q.pop();
        d = -d;
        if (dist[x] < d) continue;
        for (int i=0; i<(int)adj[x].size(); i++) {
            auto [y, d2] = adj[x][i];
            if (dis[y]) continue;
            if (dist[y] > d + d2) {
                hist[y].clear();
                hist[y].push_back({x, i});
                dist[y] = d + d2;
                q.push({-(d + d2), y});
            }
            else if (dist[y] == d + d2) {
                hist[y].push_back({x, i});
            }
        }
    }
    queue<int> que;
    vector<int> chk(n + 1);
    que.push(e);
    chk[e] = 1;
    while (que.size()) {
        int x = que.front();
        que.pop();
        for (auto [y, i] : hist[x]) {
            g[y].push_back({x, i});
            if (chk[y]) continue;
            chk[y] = 1;
            que.push(y);
        }
    }
    for (int i=1; i<=n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    int ans = 0;
    int go = s;
    while (go != e) {
        if (go != s) dis[go] = 1;
        ans += adj[go][g[go].front().second].second;
        go = adj[go][g[go].front().second].first;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int s, e;
    cin >> s >> e;
    cout << da(s, e) + da(e, s) << '\n';
}