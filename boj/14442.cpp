#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char an[1001][1001]{0};
int visit[11][1001][1001]{0};
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};
queue<tuple<int, int, int, int>> bfs;

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
    bfs.push({1, 0, 1, 1});
    visit[0][1][1] = 1;
    int ans=-1;
    while(!bfs.empty()) {
        int mv, cnt, a, b;
        tie(mv, cnt, a, b) = bfs.front();
        if(a==n&&b==m) {
            ans = mv;
            break;
        }
        bfs.pop();
        for(int d=0; d<4; d++) {
            int x=a+dx[d];
            int y=b+dy[d];
            int cnt2=cnt;
            if(x<1||x>n||y<1||y>m) continue;
            if(visit[cnt2][x][y]) continue;
            if(an[x][y]=='1') {
                if(cnt2>=k) continue;
                cnt2++;
            }
            if(visit[cnt2][x][y]) continue;
            visit[cnt2][x][y] = 1;
            bfs.push({mv+1, cnt2, x, y});
        }
    }
    cout << ans;
}