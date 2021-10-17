#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m, parent[100010], p[100010], ans[100010];

int go(int v) {
    if(v==-1) return 0;
    if(ans[v]!=-1) return ans[v];
    return ans[v] = p[v]+go(parent[v]);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> parent[i];
        ans[i] = -1;
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        p[a] += b;
    }
    for(int i=1; i<=n; i++) {
        go(i);
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
}