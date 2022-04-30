#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<ll, ll, ll>;
const ll inf = 1000000000000000000;
const ll mod = 1e9+9;
int n, m, x, y;
vector<pii> adj[101010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> x >> y;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> dist(n+1, inf);
    vector<ll> cnt(n+1, inf);
    vector<ll> ncase(n+1, inf);
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push({0, 0, x});
    dist[x] = 0;
    cnt[x] = 0;
    ncase[x] = 1;
    while (pq.size()) {
        ll cost, sum, z;
        tie(cost, sum, z) = pq.top(); pq.pop();
        if (dist[z] < cost || cnt[z] < sum) continue;
        for (auto at : adj[z]) {
            ll v, cost2;
            tie(v, cost2) = at;
            if (cost + cost2 < dist[v]) {
                dist[v] = cost+cost2;
                cnt[v] = sum + 1;
                ncase[v] = ncase[z];
                pq.push({cost + cost2, sum + 1, v});
            }
            else if (cost + cost2 == dist[v] && sum + 1 < cnt[v]) {
                cnt[v] = sum + 1;
                ncase[v] = ncase[z];
                pq.push({cost + cost2, sum + 1, v});
            }
            else if (cost + cost2 == dist[v] && sum + 1 == cnt[v]) {
                ncase[v] = (ncase[v] + ncase[z]) % mod;
            }
        }
    }
    if (dist[y] == inf) cout << -1;
    else {
        cout << dist[y] << '\n';
        cout << cnt[y] << '\n';
        cout << ncase[y] << '\n';
    }
}