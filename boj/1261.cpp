#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[4]{-1, 0, 0, 1};
int dy[4]{0, -1, 1, 0};

char miro[101][101]{0};
int visit[101][101]{0};
queue<pair<int, int>> bfs;
int m, n;

bool link(int x, int y) {
    bfs.push({x, y});
    if(x==n && y==m) {
        return true;
    }
    for(int i=0; i<4; i++) {
        int a=x+dx[i];
        int b=y+dy[i];
        if(a<1 || a>n || b<1 || b>m ||
            miro[a][b]=='1' ||
            visit[a][b]) continue;
        visit[a][b] = 1;
        if(link(a, b)) return true;
    }
    return false;
}

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

    memset(visit,0,sizeof(visit));
    visit[1][1]=1;
    int ans=0;
    for(ans=0; !link(1, 1); ans++) {
        memset(visit,0,sizeof(visit));
        visit[1][1]=1;
        while(!bfs.empty()) {
            int x, y;
            tie(x, y) = bfs.front();
            bfs.pop();
            for(int j=0; j<4; j++) {
                int a=x+dx[j];
                int b=y+dy[j];
                if(a<1 || a>n || b<1 || b>m) continue;
                miro[a][b]='0';
            }
        }
    }
    cout << ans;
}