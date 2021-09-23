#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        vector<pair<int, int>> vert[2001];
        int r=0;
        for(int i=0; i<m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if((u==g&&v==h) || (u==h&&v==g)) r=w;
            vert[u].push_back({v, w});
            vert[v].push_back({u, w});
        }
        int tn[101]{0};
        for(int i=0; i<t; i++) {
            cin >> tn[i];
        }
        int start[3]{0};
        start[0] = s;
        start[1] = g;
        start[2] = h;
        int ans[3][2001]{0};
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
                if(ans[i][v]!=-1) continue;
                ans[i][v] = w;
                for(auto a : vert[v]) {
                    if(ans[i][a.first]==-1) {
                        bfs.push({-(a.second+w), a.first});
                    }
                }
            }
        }
        vector<int> output;
        for(int i=0; i<t; i++) {
            int go=ans[0][tn[i]];
            if(ans[0][g]!=-1 && ans[2][tn[i]]!=-1) {
                int dist=ans[0][g]+r+ans[2][tn[i]];
                if(dist==go) {
                    output.push_back(tn[i]);
                    continue;
                }
            }
            if(ans[0][h]!=-1 && ans[1][tn[i]]!=-1) {
                int dist=ans[0][h]+r+ans[1][tn[i]];
                if(dist==go) {
                    output.push_back(tn[i]);
                    continue;
                }
            }
        }
        sort(output.begin(), output.end());
        for(int i : output) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}