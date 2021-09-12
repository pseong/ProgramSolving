#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    int an[51][51]{0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
        }
    }

    int dx[]{0, 0, -1, 1};
    int dy[]{-1, 1, 0, 0};

    int cnt=0;
    while(true) {
        bool move=false;
        int visit[51][51]{0};
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(!visit[i][j]) {
                    vector<pair<int, int>> team;
                    queue<pair<int,int>> bfs;
                    team.push_back({i, j});
                    bfs.push({i, j});
                    visit[i][j] = 1;
                    while(!bfs.empty()) {
                        int a, b;
                        tie(a, b) = bfs.front(); bfs.pop();
                        for(int d=0; d<4; d++) {
                            int x=a+dx[d];
                            int y=b+dy[d];
                            if(x<1||x>n||y<1||y>n) continue;
                            if(visit[x][y]) continue;
                            int gap=abs(an[a][b]-an[x][y]);
                            if(gap>=l && gap<=r) {
                                move=true;
                                team.push_back({x, y});
                                bfs.push({x, y});
                                visit[x][y] = 1;
                            }
                        }
                    }
                    int sum=0;
                    for(auto in : team) {
                        sum += an[in.first][in.second];
                    }
                    int ever=sum/team.size();
                    for(auto in : team) {
                        an[in.first][in.second] = ever;
                    }
                }
            }
        }
        if(!move) break;
        cnt++;
    }
    cout << cnt;
}