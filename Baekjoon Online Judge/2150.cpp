#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=10000;
int d[N+10], finished[N+10], id;
vector<int> vert[100010];
vector<vector<int>> SCC;
stack<int> st;

int dfs(int x) {
    d[x] = ++id;
    st.push(x);
    int parent=d[x];
    for(int y : vert[x]) {
        if(d[y]==0) parent = min(parent, dfs(y));
        else if(!finished[y]) parent = min(parent, d[y]);
    }
    if(parent==d[x]) {
        vector<int> scc;
        while(true) {
            int y=st.top();
            st.pop();
            scc.push_back(y);
            finished[y] = 1;
            if(y==x) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        vert[a].push_back(b);
    }
    for(int i=1; i<=v; i++) {
        if(d[i]==0) dfs(i);
    }
    for(auto& aut : SCC) {
        sort(aut.begin(), aut.end());
    }
    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << '\n';
    for(auto aut : SCC) {
        for(int i : aut) {
            cout << i << ' ';
        }
        cout << -1 << '\n';
    }
}