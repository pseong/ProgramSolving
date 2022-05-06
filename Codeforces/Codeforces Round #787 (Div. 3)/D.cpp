#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

vector<int> now;
vector<int> adj[202020];
vector<vector<int>> ans;
void dfs(int x, int p) {
    now.push_back(x);
    for (int y : adj[x]) {
        if (y == p) continue;
        dfs(y, x);
        now.clear();
    }
    if (adj[x].size() == 0) {
        ans.push_back(now);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int root = -1;
        for (int i=1; i<=n; i++) {
            int p;
            cin >> p;
            if (i == p) {
                root = i;
            }
            else {
                adj[p].push_back(i);
            }
        }
        dfs(root, root);
        cout << ans.size() << '\n';
        for (int i=0; i<ans.size(); i++) {
            cout << ans[i].size() << '\n';
            for (int x : ans[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        
        now.clear();
        for (int i=1; i<=n; i++) {
            adj[i].clear();
        }
        ans.clear();
    }
}