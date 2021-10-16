#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<int> v[500010];
int sum=0;
int dfs(int node, int par, int depth) {
    int cnt=v[node].size()-1;
    if(node==1) cnt++;
    if(cnt==0) sum += depth;
    for(int i : v[node]) {
        if(i==par) continue;
        dfs(i, node, depth+1);
    }
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
    dfs(1, 0, 0);
    if(sum&1) cout << "Yes";
    else cout << "No";
}