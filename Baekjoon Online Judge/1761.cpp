#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define pb push_back
#define F first
#define S second

int depth[40010];
int parent[40010][20];
vector<pii> v[40010];
int dist2[40010];
int dist[40010][20];
void dfs(int node, int d, int pre, int sum) {
    depth[node] = d;
    for(auto i : v[node]) {
        if(i.first==pre) continue;
        parent[i.first][0] = node;
        dist2[i.first] = sum+i.second;
        dist[i.first][0] = i.second;
        dfs(i.first, d+1, node, dist2[i.first]);
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

    dfs(1, 0, 0, 0);
    for(int k=1; k<=19; k++) {
        for(int i=1; i<=n; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
            dist[i][k] = dist[i][k-1]+dist[parent[i][k-1]][k-1];
        }
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        int copy_a=a;
        int copy_b=b;

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