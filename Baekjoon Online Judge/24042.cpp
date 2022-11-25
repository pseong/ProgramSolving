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

vector<pi> adj[101010];
map<int, int> idx[101010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({i, b});
        adj[b].push_back({i, a});
    }
    const ll inf = 1e15;
    vector<ll> dist(n + 1, inf);
    priority_queue<pair<ll, int>> q;
    q.push({0, 1});
    dist[1] = 0;
    while (q.size()) {
        auto [d, x] = q.top();
        d = -d;
        q.pop();
        if (dist[x] < d) continue;
        for (auto [idx, y] : adj[x]) {
            int t = d % m;
            if (idx < t) idx += m;
            ll cal = d + idx - t + 1;
            if (dist[y] > cal) {
                dist[y] = cal;
                q.push({-cal, y});
            }
        }
    }
    cout << dist[n] << '\n';
}