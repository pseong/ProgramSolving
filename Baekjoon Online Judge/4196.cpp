#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int id, sccId;
int d[101010], sd[101010], finished[101010];
stack<int> st;

vector<int> adj[101010];

int dfs(int x) {
    d[x] = ++id;
    st.push(x);
    int parent = d[x];
    for (int y : adj[x]) {
        if (d[y] == 0) parent = min(parent, dfs(y));
        else if (finished[y] == 0) parent = min(parent, d[y]);
    }
    if (parent == d[x]) {
        ++sccId;
        while (true) {
            int t = st.top();
            st.pop();
            finished[t] = true;
            sd[t] = sccId;
            if (t == x) break;
        }
    }
    return parent;
}

void solve() {
    int n, m;
    cin >> n >> m;
    id = 0;
    sccId = 0;
    for (int i=0; i<=n; i++) {
        adj[i].clear();
        d[i] = 0;
        sd[i] = 0;
        finished[i] = 0;
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        if (d[i] == 0) dfs(i);
    }
    vector<int> in(sccId + 1);
    for (int x=1; x<=n; x++) {
        for (int y : adj[x]) {
            if (sd[y] == sd[x]) continue;
            in[sd[y]]++;
        }
    }
    int ans = 0;
    for (int i=1; i<=sccId; i++) {
        if (in[i] == 0) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}