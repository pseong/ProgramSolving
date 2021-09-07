#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char an[1001][1001]{0};
int visit[11][2][1001][1001]{0};
int dx[]{-1, 1, 0, 0, 0};
int dy[]{0, 0, -1, 1, 0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> an[i][j];
        }
    }

    queue<tuple<int, int, int, int>> bfs;
    bfs.push({1, 1, 1, 0});
    visit[0][1][1][1] = 1;
    int ans=-1;
    while(!bfs.empty()) {
        int i, j, mv, cnt;
        tie(i, j, mv, cnt) = bfs.front();
        bfs.pop();
        if(i==n&&j==m) {
            ans = mv;
            break;
        }
        for(int d=0; d<5; d++) {
            int x=i+dx[d];
            int y=j+dy[d];
            int cnt2=cnt;
            if(x<1||x>n||y<1||y>m) continue;
            if(visit[cnt2][(mv+1)%2][x][y]) continue;
            if(an[x][y]=='1') {
                if(cnt2>=k||mv%2==0) continue;
                cnt2++;
            }
            visit[cnt2][(mv+1)%2][x][y] = 1;
            bfs.push({x, y, mv+1, cnt2});
        }
    }
    cout << ans;
}