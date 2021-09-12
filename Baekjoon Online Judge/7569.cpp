#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[]{0,0,0,1,-1,0};
int dy[]{0,1,-1,0,0,0};
int dz[]{-1,0,0,0,0,1};

int visit[101][101][101]{0};
int an[101][101][101]{0};
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    queue<tuple<int, int, int, int>> bfs;
    int n, m, h;
    cin >> m >> n >> h;
    for(int k=1; k<=h; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cin >> an[k][i][j];
                if(an[k][i][j] == 1) {
                    bfs.push({k, i, j, 0});
                    visit[k][i][j] = 1;
                }
            }
        }
    }

    int ans=0;
    while(!bfs.empty()) {
        int k, i, j, cnt;
        tie(k, i, j, cnt) = bfs.front();
        ans = max(ans, cnt);
        bfs.pop();
        for(int d=0; d<6; d++) {
            int x=i+dx[d];
            int y=j+dy[d];
            int z=k+dz[d];
            if(x<1||x>n||y<1||y>m||z<1||z>h) continue;
            if(visit[z][x][y]) continue;
            if(an[z][x][y]!=0) continue;
            visit[z][x][y] = 1;
            an[z][x][y] = 1;
            bfs.push({z,x,y,cnt+1});
        }
    }
    int good=true;
    for(int k=1; k<=h; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(an[k][i][j]==0) good=false;
            }
        }
    }
    if(good) cout << ans;
    else cout << -1;
}