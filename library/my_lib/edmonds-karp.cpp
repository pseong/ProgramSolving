#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2020];
int c[2020][2020], f[2020][2020], d[2020];
int s = 2001;
int t = 2002;

int maxFlow() {
    int ans = 0;
    while (true) {
        memset(d, -1, sizeof d);
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (d[y] == -1 && c[x][y] - f[x][y] > 0) {
                    d[y] = x;
                    q.push(y);
                }
            }
        }
        if (d[t] == -1) break;
        int flow = INT_MAX;
        for (int x=t; x!=s; x=d[x]) {
            flow = min(flow, c[d[x]][x] - f[d[x]][x]);
        }
        for (int x=t; x!=s; x=d[x]) {
            f[d[x]][x] += flow;
            f[x][d[x]] -= flow;
        }
        ans += flow;
    }
    return ans;
}