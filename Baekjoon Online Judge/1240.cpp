#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m, parent[1010][20], dist[1010][20], depth[1010];
vector<pii> v[1010];

void dfs(int node, int par, int dpth) {
    for(auto a : v[node]) {
        if(a.F==par) continue;
        dist[a.F][0] = a.S;
        depth[a.F] = dpth+1;
        parent[a.F][0] = node;
        dfs(a.F, node, dpth+1);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1, 0, 0);
    for(int k=1; k<=19; k++) {
        for(int i=1; i<=n; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
            dist[i][k] = dist[i][k-1]+dist[parent[i][k-1]][k-1];
        }
    }

    for(int z=0; z<m; z++) {
        int a, b;
        cin >> a >> b;
        if(depth[a]<depth[b]) swap(a, b);

        int ans=0;
        for(int k=19; k>=0; k--) {
            if(depth[a]-depth[b]>=(1<<k)) {
                ans += dist[a][k];
                a = parent[a][k];
            }
        }

        for(int k=19; k>=0; k--) {
            if(parent[a][k]!=parent[b][k]) {
                ans += dist[a][k];
                ans += dist[b][k];
                a = parent[a][k];
                b = parent[b][k];
            }
        }
        if(a!=b) {
            ans += dist[a][0];
            ans += dist[b][0];
            a = parent[a][0];
            b = parent[b][0];
        }
        cout << ans << '\n';
    }
}