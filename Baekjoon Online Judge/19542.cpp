#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, s, d, state[100010], ans=-1;
vector<int> v[100010];

int dfs(int node, int par) {
    int res=0;
    for(int i : v[node]) {
        if(i==par) continue;
        res = max(res, dfs(i, node));
    }
    if(res<d) state[node] = 1;
    return res+1;
}

void dfs2(int node, int par) {
    if(state[node]==1) {
        ans--;
        return;
    }
    for(int i : v[node]) {
        if(i==par) continue;
        ans++;
        dfs2(i, node);
    }
    ans++;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> s >> d;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(s, 0);
    dfs2(s, 0);
    cout << max(ans, 0);
}