#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char wall[9][9][9]{0};

int dx[]{-1, -1, -1, 0, 0, 1, 1, 1, 0};
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for(int i=1; i<=8; i++) {
        for(int j=1; j<=8; j++) {
            cin >> wall[0][i][j];
        }
    }

    for(int k=1; k<9; k++) {
        for(int i=8; i>=1+k; i--) {
            for(int j=1; j<=8; j++) {
                wall[k][i][j] = wall[0][i-k][j];
            }
        }
        for(int i=1; i<=k; i++) {
            for(int j=1; j<=8; j++) {
                wall[k][i][j] = '.';
            }
        }
    }

    queue<tuple<int, int, int>> bfs;
    bfs.push({8, 1, 0});
    int visit[9][9][9]{0};
    visit[0][8][1] = 1;
    int ans=0;
    while(!bfs.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = bfs.front();
        if(cnt>8) cnt = 8;
        if(x==1&&y==8) {
            ans=1;
            break;
        }
        bfs.pop();
        for(int d=0; d<9; d++) {
            int i=x+dx[d];
            int j=y+dy[d];
            if(i<1||i>8||j<1||j>8) continue;
            if(visit[cnt][i][j]) continue;
            if(cnt<=8 && wall[cnt][i][j]=='#') continue;
            if(cnt<=7 && wall[cnt+1][i][j]=='#') continue;
            if(d!=8) visit[cnt][i][j] = 1;
            bfs.push({i, j, cnt+1});
        }
    }
    cout << ans;
}