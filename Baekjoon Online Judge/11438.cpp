#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int depth[100010]{0};
int parent[100010][20]{0};
int p_cost_min[100010][20]{0};
int p_cost_max[100010][20]{0};
vector<pii> v[100010];
void dfs(int node, int d, int pre) {
    depth[node] = d;
    for(auto i : v[node]) {
        if(i.first==pre) continue;
        parent[i.first][0] = node;
        p_cost_min[i.first][0] = i.second;
        p_cost_max[i.first][0] = i.second;
        dfs(i.first, d+1, node);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(1, 0, 0);

    for(int k=1; k<=19; k++) {
        for(int i=1; i<=n; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
            p_cost_min[i][k] = min(p_cost_min[i][k-1], p_cost_min[parent[i][k-1]][k-1]);
            p_cost_max[i][k] = max(p_cost_max[i][k-1], p_cost_max[parent[i][k-1]][k-1]);
        }
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        int ans_min=1000000;
        int ans_max=0;
        if(depth[a]<depth[b]) swap(a, b);
        for(int k=19; k>=0; k--) {
            if(depth[a]-depth[b]>=(1<<k)) {
                ans_min = min(ans_min, p_cost_min[a][k]);
                ans_max = max(ans_max, p_cost_max[a][k]);
                a = parent[a][k];
            }
        }

        for(int k=19; k>=0; k--) {
            if(parent[a][k]!=parent[b][k]) {
                ans_min = min(ans_min, p_cost_min[a][k]);
                ans_min = min(ans_min, p_cost_min[b][k]);
                ans_max = max(ans_max, p_cost_max[a][k]);
                ans_max = max(ans_max, p_cost_max[b][k]);
                a = parent[a][k];
                b = parent[b][k];
            }
        }
        if(a!=b) cout << min({ans_min, p_cost_min[a][0], p_cost_min[b][0]}) << ' ' << max({ans_max, p_cost_max[a][0], p_cost_max[b][0]}) << '\n';
        else cout << ans_min << ' ' << ans_max << '\n';
    }
}