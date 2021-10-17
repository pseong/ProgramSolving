#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m, parent[100010];

int getParent(int i) {
    if(i==parent[i]) return i;
    return parent[i] = getParent(parent[i]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a>b) swap(a, b);
    parent[b] = a;
}

bool findParent(int a, int b) {
    return getParent(a)==getParent(b);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    int ans=0;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        if(findParent(u, v)) ans++;
        else {
            unionParent(u, v);
        }
    }
    for(int i=2; i<=n; i++) {
        if(!findParent(i-1, i)) {
            ans++;
            unionParent(i-1, i);
        }
    }
    cout << ans;
}