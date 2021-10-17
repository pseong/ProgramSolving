#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<pii> v[10010];
int ans[2];

void dfs(int node, int par, int dist) {
    for(auto a : v[node]) {
        if(a.F==par) continue;
        if(dist+a.S>ans[1]) {
            ans[0] = a.F;
            ans[1] = dist+a.S;
        }
        dfs(a.F, node, dist+a.S);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int a, b, c;
    while(cin >> a >> b >> c) {
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(1, 0, 0);
    int node=ans[0];
    ans[1] = 0;
    dfs(ans[0], 0, 0);
    cout << ans[1];
}