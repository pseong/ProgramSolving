#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> v[101010];
int ans[101010];

void dfs(int node, int par, int c) {
    ans[node] = v[node].size() * c;
    for (int x : v[node]) {
        if (x == par) continue;
        else {
            dfs(x, node, -c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            v[i].clear();
        }
        for (int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1, 0, 1);
        for (int i=1; i<=n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}