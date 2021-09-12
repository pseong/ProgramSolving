#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[4]{-1, 0, 0, 1};
int dy[4]{0, -1, 1, 0};

char miro[101][101]{0};
int dist[101][101]{0};
deque<pair<int, int>> bfs;
int m, n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> miro[i][j];
        }
    }

    memset(dist,-1,sizeof(dist));
    bfs.push_back({1,1});
    dist[1][1]=0;
    while(!bfs.empty()) {
        int x, y;
        tie(x, y) = bfs.front();
        bfs.pop_front();
        for(int j=0; j<4; j++) {
            int a=x+dx[j];
            int b=y+dy[j];
            if(a<1 || a>n || b<1 || b>m || dist[a][b] != -1) continue;
            if(miro[a][b]=='1') {
                dist[a][b] = dist[x][y]+1;
                bfs.push_back({a, b});
            } else {
                dist[a][b] = dist[x][y];
                bfs.push_front({a, b});
            }
        }
    }
    cout << dist[n][m];
}