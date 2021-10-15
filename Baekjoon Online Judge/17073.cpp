#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<int> v[500010];
int leaf=0;
void dfs(int node, int par) {
    bool is_leaf=true;
    for(int i : v[node]) {
        if(i==par) continue;
        is_leaf=false;
        dfs(i, node);
    }
    if(is_leaf) leaf++;
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, w;
    cin >> n >> w;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    cout << fixed << setprecision(5) << (double)w/leaf;
}