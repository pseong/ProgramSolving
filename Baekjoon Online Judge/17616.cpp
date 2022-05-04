#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

vector<int> adj[2][101010];
bool chk[2][101010];

int dfs(int x) {
    if (chk[0][x]) return 0;
    int ret = 1;
    for (int y : adj[0][x]) {
        ret += dfs(y);
    }
    chk[0][x] = true;
    return ret;
}

int dfs2(int x) {
    if (chk[1][x]) return 0;
    int ret = 1;
    for (int y : adj[1][x]) {
        ret += dfs2(y);
    }
    chk[1][x] = true;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> in(n+1, 0);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }
    if (adj[0][x].empty() && adj[1][x].empty()) {
        cout << 1 << ' ' << n;
        return 0;
    }
    int back = dfs(x); back--;
    int front = dfs2(x); front--;
    cout << front + 1 << ' ' << n - back;
}