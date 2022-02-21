#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int inf = 1000000000;
int n, m, k, x;
vector<int> v[300010];
int dist[300010];
bool check[300010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> x;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    fill(dist, dist+300010, inf);

    priority_queue<pii> que;
    que.push({0, x});
    dist[x] = 0;
    while (!que.empty()) {
        int cost, node;
        tie(cost, node) = que.top();
        cost = -cost;
        que.pop();
        if (check[node]) {
            continue;
        }
        check[node] = 1;
        for (int y : v[node]) {
            if (dist[y] > cost + 1) {
                dist[y] = cost + 1;
                que.push({-cost-1, y});
            }
        }
    }

    bool prt = false;
    for (int i=1; i<=n; i++) {
        if (dist[i] == k) {
            prt = true;
            cout << i << '\n';
        }
    }
    if (!prt) {
        cout << -1 << '\n';
    }

    return 0;
}