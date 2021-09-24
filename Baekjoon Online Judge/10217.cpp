#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int res[101][10001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<tuple<int, int, int>> vert[101];
        while(k--) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            vert[u].push_back({v, c, d});
        }

        for(int i=1; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                res[i][j] = 1000000000;
            }
        }
        priority_queue<tuple<int, int, int>> bfs;
        bfs.push({0, 0, 1});
        res[1][0] = 0;
        while(!bfs.empty()) {
            int v, c, d;
            tie(d, c, v) = bfs.top();
            d = -d;
            bfs.pop();
            if(res[v][c] < d) continue;
            if(v==n) break;
            for(auto a : vert[v]) {
                int v2, c2, d2;
                tie(v2, c2, d2) = a;
                if(c+c2>m || res[v2][c+c2]<=d+d2) continue;
                res[v2][c+c2] = d+d2;
                bfs.push({-(d+d2), c+c2, v2});
            }
        }
        int ans=1000000000;
        for(int i=1; i<=m; i++) {
            ans = min(ans, res[n][i]);
        }
        if(ans==1000000000) cout << "Poor KCM\n";
        else cout << ans << '\n';
    }
}