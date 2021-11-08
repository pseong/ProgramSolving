#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=300000;
vector<int> v[N+10];
int vis[N+10];
ll cnt;

void dfs(int x, int parent) {
    if(vis[x]) return;
    vis[x] = 1;
    int child=((x==1) ? 0 : -1);
    child += v[x].size();
    cnt += max(child-2, 0);
    for(int y : v[x]) {
        if(y==parent) continue;
        dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll all=0;
}