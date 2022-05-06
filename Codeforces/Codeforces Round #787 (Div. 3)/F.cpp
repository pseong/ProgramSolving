#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int n, k, x, y;
vector<int> adj[202020];
int must[202020];

pii dfs(int a, int p) {
    int ret = 0;
    int flag = 0;
    for (int b : adj[a]) {
        if (b == p) continue;
        pii d = dfs(b, a);
        if (d.second) flag = 1;
        ret += d.first;
    }

    if (a == y) flag = 1;
    if (!flag) {
        if (ret) return {ret+2, 0};
        else if (must[a]) return {2, 0};
        return {0, 0};
    }
    else return {ret+1, 1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> n >> k >> x >> y;
        for (int i=1; i<=n; i++) {
            adj[i].clear();
            must[i] = 0;
        }

        for (int i=0; i<k; i++) {
            int a;
            cin >> a;
            must[a] = 1;
        }
        for (int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << dfs(x, 0).first-1 << '\n';
    }
}