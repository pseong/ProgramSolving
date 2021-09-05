#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

char an[1001][1001]{0};
int visit[1001][1001][2]{0};

int dx[]{0, 0, -1, 1};
int dy[]{-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> an[i][j];
        }
    }


    int ans=-1;
    queue<tuple<int, int, int, int>> bfs;
    bfs.push({1, 1, 1, 0});
    while(!bfs.empty()) {
        int x, y, cnt, use;
        tie(x, y, cnt, use) = bfs.front();
        if(x==n&&y==m) {
            ans = cnt;
            break;
        }
        bfs.pop();
        for(int d=0; d<4; d++) {
            int i=x+dx[d];
            int j=y+dy[d];
            if(i<1||i>n||j<1||j>m) continue;
            if(visit[i][j][use]) continue;
            if(an[i][j]=='1' && !use) {
                visit[i][j][1] = 1;
                bfs.push({i, j, cnt+1, 1});
            } else if(an[i][j]=='0') {
                visit[i][j][use] = 1;
                bfs.push({i, j, cnt+1, use});
            }
        }
    }
    cout << ans;
}