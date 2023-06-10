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

vector<int> adj[202020];
int h[202020];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(h, -1, sizeof h);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pq<pi> q;
    for (int i=0; i<k; i++) {
        int p, s;
        cin >> p >> s;
        h[p] = s;
        q.push({s, p});
    }

    while (q.size()) {
        auto [s, v] = q.top();
        q.pop();
        for (auto u : adj[v]) {
            if (s-1 > h[u]) {
                h[u] = s-1;
                q.push({s-1, u});
            }
        }
    }

    vector<int> ans;
    for (int i=1; i<=n; i++) {
        if (h[i] >= 0) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
}