#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int ans=0;
vector<int> v[100];
void dfs(int node, int par) {
    int cnt=0;
    for(int i : v[node]) {
        if(i==par) continue;
        cnt++;
    }
    if(cnt==0) ans++;
    for(int i : v[node]) {
        if(i==par) continue;
        dfs(i, node);
    }
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int root=-1;
    vector<int> input;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }
    int eras;
    cin >> eras;
    for(int i=0; i<n; i++) {
        int a=input[i];
        if(a==-1) {
            root = i;
        }
        if(i==eras || a==eras) continue;
        else {
            v[i].push_back(a);
            v[a].push_back(i);
        }
    }
    dfs(root, -1);
    if(eras!=root) cout << ans;
    else cout << 0;
}