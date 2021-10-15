#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int k, an[1500], tree[1500];
void dfs(int node, int s, int e) {
    if(s==e) {
        tree[node] = an[s];
        return;
    }
    int m=(s+e)/2;
    tree[node] = an[m];
    dfs(node*2, s, m-1);
    dfs(node*2+1, m+1, e);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> k;
    for(int i=1; i<(1<<k); i++) {
        cin >> an[i];
    }
    dfs(1, 1, (1<<k)-1);
    queue<pii> q;
    q.push({1, 0});
    int depth=0;
    while(!q.empty()) {
        int a, d;
        tie(a, d)=q.front();
        q.pop();
        if(d!=depth) {
            cout << '\n';
            depth++;
        }
        cout << tree[a] << ' ';
        if(a*2<(1<<k)) {
            q.push({a*2, d+1});
            q.push({a*2+1, d+1});
        }
    }
}