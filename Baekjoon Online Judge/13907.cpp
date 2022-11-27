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

vector<pi> adj[1010];
int n, m, k, s, t;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >>n >> m >> k >> s >> t;
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    const int inf = 300000000;
    vector<int> dst(n + 1, inf);
    vector<int> cnt(n + 1, 0);
    priority_queue<pi> q;
    dst[s] = 0;
    q.push({0, s});
    while (q.size()) {
        auto [d, x] = q.top();
        q.pop();
        d = -d;
        if (dst[x] < d) continue;
        for (auto [y, d2] : adj[x]) {
            if (dst[y] > d + d2) {
                dst[y] = d + d2;
                cnt[y] = cnt[x] + 1;
                q.push({-(d + d2), y});
            }
        }
    }
    vector<vector<int>> dist(n + 1, vector<int>(cnt[t] + 1, inf));
    priority_queue<ti> que;
    dist[s][0] = 0;
    que.push({0, s, 0});
    while (que.size()) {
        auto [d, x, c] = que.top();
        que.pop();
        d = -d;
        if (c == cnt[t] || dist[x][c] < d) continue;
        for (auto [y, d2] : adj[x]) {
            if (dist[y][c + 1] > d + d2) {
                dist[y][c + 1] = d + d2;
                que.push({-(d + d2), y, c + 1});
            }
        }
    }
    vector<pi> ans;
    ans.push_back({dst[t], cnt[t]});
    int now = dst[t];
    for (int i=cnt[t]-1; i>=1; i--) {
        if (dist[t][i] > now) {
            now = dist[t][i];
            ans.push_back({dist[t][i], i});
        }
    }
    cout << ans.front().first << '\n';
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        int mn = INT_MAX;
        for (int j=0; j<(int)ans.size(); j++) {
            ans[j].first += ans[j].second * a;
            mn = min(mn, ans[j].first);
        }
        cout << mn << '\n';
    }
}