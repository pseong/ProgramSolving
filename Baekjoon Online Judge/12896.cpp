#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
vector<int> v[N+10];
int vis[N+10];
pii dfs(int x, int dist) {
    int ret=x;
    int mx=dist;
    for(int y : v[x]) {
        if(vis[y]) continue;
        vis[y] = 1;
        pii a=dfs(y, dist+1);
        if(mx < a.S) {
            mx = a.S;
            ret = a.F;
        }
    }
    return {ret, mx};
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vis[1] = 1;
    pii x=dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    vis[x.F] = 1;
    pii y=dfs(x.F, 0);
    cout << (y.S+1)/2;
}