#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=500000;
vector<int> v[N+10], start;
int n, m, s, p, id, sccId=1, sm[N+10], an[N+10], pn[N+10], d[N+10], sd[N+10], sn[N+10];
stack<int> st;
vector<int> v2[N+10];

int dfs(int x) {
    d[x] = ++id;
    int parent=d[x];
    st.push(x);
    for(int y : v[x]) {
        if(!d[y]) parent = min(parent, dfs(y));
        else if(!sd[y]) parent = min(parent, d[y]);
    }
    if(parent==d[x]) {
        int sum=0;
        while(true) {
            int y=st.top();
            st.pop();
            sd[y] = sccId;
            sum += an[y];
            if(x==y) break;
        }
        sn[sccId] = sum;
        sccId++;
    }
    return parent;
}

void dfs2(int x, int amt) {
    amt += sn[x];
    sm[x] = max(sm[x], amt);
    for(int y : v2[x]) {
        if(sm[y]<amt+sn[y]) dfs2(y, amt);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    cin >> s >> p;
    for(int i=0; i<p; i++) {
        cin >> pn[i];
    }

    for(int i=1; i<=n; i++) {
        if(d[i]==0) dfs(i);
    }
    for(int x=1; x<=n; x++) {
        for(int y : v[x]) {
            if(sd[x]==sd[y]) continue;
            v2[sd[x]].push_back(sd[y]);
        }
    }
    dfs2(sd[s], 0);
    int ans=0;
    for(int i=0; i<p; i++) {
        ans = max(ans, sm[sd[pn[i]]]);
    }
    cout << ans;
}