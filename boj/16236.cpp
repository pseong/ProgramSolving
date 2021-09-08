#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[]{-1, 0, 0, 1};
int dy[]{0, -1, 1, 0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int an[21][21]{0};
    int n;
    cin >> n;

    int x_n;
    int y_n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
            if(an[i][j]==9) {
                x_n = i;
                y_n = j;
                an[i][j] = 0;
            }
        }
    }

    int lv=2;
    int exp=0;
    int ans=0;
    while(true) {
        queue<tuple<int, int, int>> bfs;
        bfs.push({x_n, y_n, 0});
        int visit[21][21]{0};
        visit[x_n][y_n] = 1;
        int poss[21][21]{0};
        int find=false;
        while(!bfs.empty()) {
            int i, j, cnt;
            tie(i, j, cnt) = bfs.front();
            if(an[i][j]>0&&an[i][j]!=lv) {
                poss[i][j] = cnt;
                find = true;
            }
            bfs.pop();
            for(int d=0; d<4; d++) {
                int x=i+dx[d];
                int y=j+dy[d];
                if(x<1||x>n||y<1||y>n) continue;
                if(visit[x][y]) continue;
                if(an[x][y]!=0 && an[x][y] > lv) continue;
                visit[x][y] = 1;
                bfs.push({x, y, cnt+1});
            }
        }
        if(!find) break;
        int mini=1000;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(poss[i][j]) mini = min(mini, poss[i][j]);
            }
        }
        bool eat=false;
        for(int i=1; i<=n; i++) {
            if(eat) break;
            for(int j=1; j<=n; j++) {
                if(eat) break;
                if(poss[i][j]==mini) {
                    an[i][j] = 0;
                    exp++;
                    if(exp==lv) {
                        exp = 0;
                        lv++;
                    }
                    x_n = i;
                    y_n = j;
                    eat = true;
                    ans += poss[i][j];
                }
            }
        }
    }
    cout << ans;
}