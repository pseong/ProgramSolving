#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define pb push_back
#define F first
#define S second

int n, depth[510], parent[510][20];
vector<int> v[510];

void dfs(int node, int par, int d) {
    for(int i : v[node]) {
        if(i==par) continue;
        parent[i][0] = node;
        depth[i] = d+1;
        dfs(i, node, d+1);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 0);
    for(int k=1; k<20; k++) {
        for(int i=1; i<=n; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(depth[a]<depth[b]) swap(a, b);
        for(int k=19; k>=0; k--) {
            if(depth[a]-depth[b]>=(1<<k)) {
                a = parent[a][k];
            }
        }
        for(int k=19; k>=0; k--) {
            if(parent[a][k]!=parent[b][k]) {
                a = parent[a][k];
                b = parent[b][k];
            }
        }
        if(a!=b) {
            a = parent[a][0];
            b = parent[b][0];
        }
        cout << a << '\n';
    }
}