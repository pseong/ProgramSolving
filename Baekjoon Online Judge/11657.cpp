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

ll dist[550], cycle[550];
bool inQ[550];
const int inf = 1010101010;
vector<pi> adj[550];

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for (int i=0; i<550; i++) {
        dist[i] = inf;
    }

    queue<int> q;
    dist[1] = 0;
    cycle[1] = 1;
    inQ[1] = true;
    q.push(1);
    while (q.size()) {
        int x = q.front();
        q.pop();
        inQ[x] = false;
        for (auto [y, w] : adj[x]) {
            if (dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                cycle[y]++;
                if (inQ[y]) continue;
                if (cycle[y] >= n) {
                    cout << -1 << '\n';
                    return;
                }
                inQ[y] = true;
                q.push(y);
            }
        }
    }

    for (int i=2; i<=n; i++) {
        if (dist[i] == inf) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}