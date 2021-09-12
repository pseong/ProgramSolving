#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[]{0, 0, -1, 1};
int dy[]{-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int an[8][8]{0};
    int visit[8][8]{0};
    vector<pair<int ,int>> v;
    int cnt_0=0;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> an[i][j];
            if(an[i][j]==2) {
                v.push_back({i, j});
            } else if(an[i][j]==0) cnt_0++;
        }
    }
    if(cnt_0<=3) {
        cout << 0;
        return 0;
    }
    cnt_0 -= 3;
    int ans=-1;
    for(int a=0; a<n*m; a++) {
        if(an[a/m][a%m]!=0) continue;
        an[a/m][a%m]=1;
        for(int b=a+1; b<n*m; b++) {
            if(an[b/m][b%m]!=0) continue;
            an[b/m][b%m]=1;
            for(int c=b+1; c<n*m; c++) {
                if(an[c/m][c%m]!=0) continue;
                an[c/m][c%m]=1;
                int res=cnt_0;
                res += v.size();
                int visit[10][10]{0};
                queue<pair<int, int>> bfs;
                for(auto aut : v) {
                    visit[aut.first][aut.second] = 1;
                    bfs.push(aut);
                }
                while(!bfs.empty()) {
                    res--;
                    int i, j;
                    tie(i, j) = bfs.front();
                    bfs.pop();
                    for(int d=0; d<4; d++) {
                        int x=i+dx[d];
                        int y=j+dy[d];
                        if(x<0||x>=n||y<0||y>=m) continue;
                        if(visit[x][y]) continue;
                        if(an[x][y]==1) continue;
                        visit[x][y] = 1;
                        bfs.push({x, y});
                    }
                }
                if(ans==-1) ans = res;
                else ans = max(ans, res);
                an[c/m][c%m]=0;
            }
            an[b/m][b%m]=0;
        }
        an[a/m][a%m]=0;
    }
    cout << ans;
}