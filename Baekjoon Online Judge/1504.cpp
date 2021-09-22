#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

vector<pair<int, int>> vert[801];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vert[u].push_back({v, w});
        vert[v].push_back({u, w});
    }
    int start[3]{0};
    start[0] = 1;
    cin >> start[1] >> start[2];
    int ans[3][801]{0};
    memset(ans[0], -1, sizeof(ans[0]));
    memset(ans[1], -1, sizeof(ans[1]));
    memset(ans[2], -1, sizeof(ans[2]));
    for(int i=0; i<3; i++) {
        priority_queue<pair<int, int>> bfs;
        bfs.push({0, start[i]});
        while(!bfs.empty()) {
            int v, w;
            tie(w, v) = bfs.top();
            bfs.pop();
            w = -w;
            if(ans[i][v]==-1) {
                ans[i][v] = w;
                for(auto a : vert[v]) {
                    if(ans[i][a.first]==-1) {
                        bfs.push({-(a.second+w), a.first});
                    }
                }
            }
        }
    }
    int a=-1;
    if(ans[0][start[1]]!=-1 && ans[1][start[2]]!=-1 && ans[2][n]!= -1) {
        a = ans[0][start[1]]+ans[1][start[2]]+ans[2][n];    
    }
    int b=-1;
    if(ans[0][start[2]]!=-1 && ans[2][start[1]]!=-1 && ans[1][n]!= -1) {
        b = ans[0][start[2]]+ans[2][start[1]]+ans[1][n];
    }
    if(a==-1 && b==-1) cout << -1;
    else cout << min(a, b);
}