#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

vector<pair<int, int>> vert[20001];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int v, e;
    cin >> v >> e;
    int start;
    cin >> start;
    for(int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vert[u].push_back({v, w});
    }

    int ans[20000]{0};
    memset(ans, -1, sizeof(ans));
    priority_queue<pair<int, int>> bfs;
    bfs.push({0, start});
    while(!bfs.empty()) {
        int v, w;
        tie(w, v) = bfs.top();
        bfs.pop();
        w = -w;
        if(ans[v]==-1) {
            ans[v] = w;
            for(auto a : vert[v]) {
                if(ans[a.first]==-1) {
                    bfs.push({-(a.second+w), a.first});
                }
            }
        }
    }
    
    for(int i=1; i<=v; i++) {
        if(ans[i]==-1) cout << "INF\n";
        else cout << ans[i] << '\n';
    }
}