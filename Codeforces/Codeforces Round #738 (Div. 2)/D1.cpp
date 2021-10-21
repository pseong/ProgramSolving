#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=1000;
int parent[N+10];
int parent2[N+10];

int getParent(int i) {
    if(i==parent[i]) return i;
    return parent[i] = getParent(parent[i]);
}

int getParent2(int i) {
    if(i==parent2[i]) return i;
    return parent2[i] = getParent2(parent2[i]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a>b) swap(a, b);
    parent[b] = a;
}

void unionParent2(int a, int b) {
    a = getParent2(a);
    b = getParent2(b);
    if(a>b) swap(a, b);
    parent2[b] = a;
}

bool findParent(int a, int b) {
    return getParent(a)==getParent(b);
}

bool findParent2(int a, int b) {
    return getParent2(a)==getParent2(b);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for(int i=1; i<=n; i++) {
        parent2[i] = i;
    }

    for(int i=0; i<m1; i++) {
        int u, v;
        cin >> u >> v;
        unionParent(u, v);
    }
    for(int i=0; i<m2; i++) {
        int u, v;
        cin >> u >> v;
        unionParent2(u, v);
    }

    vector<pii> ans;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if((!findParent(i, j)) && (!findParent2(i, j))) {
                unionParent(i, j);
                unionParent2(i, j);
                ans.push_back({i, j});
            }
        }
    }
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i].F << ' ' << ans[i].S << '\n';
    }
}