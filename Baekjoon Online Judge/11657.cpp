#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<tuple<int, int, int>> edge;
int n, m;
ll dist[510];
const int inf = 1000000000;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }

    fill(dist, dist+n+1, inf);

    bool cycle = false;
    dist[1] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<edge.size(); j++) {
            int from, to, cost;
            tie(from, to, cost) = edge[j];
            if (dist[from] != inf && dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                if (i==n) cycle = true;
            }
        }
    }

    if (cycle) {
        cout << -1 << '\n';
    }
    else {
        for (int i=2; i<=n; i++) {
            if (dist[i] == inf) dist[i] = -1;
            cout << dist[i] << '\n';
        }
    }
    return 0;
}