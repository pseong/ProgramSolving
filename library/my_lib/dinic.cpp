#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2020];
int c[2020][2020], f[2020][2020], lv[2020], work[2020];
int s = 2001;
int t = 2002;

bool bfs() {
    memset(lv, -1, sizeof lv);
    lv[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (lv[y] == -1 && c[x][y] - f[x][y] > 0) {
                lv[y] = lv[x] + 1;
                q.push(y);
            }
        }
    }
    return lv[t] != -1;
}

int dfs(int x, int flow) {
    if (x == t) return flow;
    for (int& i=work[x]; i<(int)adj[x].size(); i++) {
        int y = adj[x][i];
        if (lv[y] == lv[x] + 1 && c[x][y] - f[x][y] > 0) {
            int ret = dfs(y, min(flow, c[x][y] - f[x][y]));
            if (ret > 0) {
                f[x][y] += ret;
                f[y][x] -= ret;
                return ret;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int ans = 0;
    while (bfs()) {
        memset(work, 0, sizeof work);
        while (true) {
            int flow = dfs(s, INT_MAX);
            if (flow == 0) break;
            ans += flow;
        }
    }
    return ans;
}