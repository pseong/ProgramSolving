#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int visit[1001][1001]{0};
int poss[1001][1001]{0};
int ans[1001][1001]{0};
int team[1001][1001]{0};
int dx[]{0, 0, -1, 1};
int dy[]{-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    char an[1001][1001]{0};
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> an[i][j];
            if(an[i][j]=='1') an[i][j] = 'a';
        }
    }
    int teams=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(visit[i][j]) continue;
            if(an[i][j]=='0') {
                teams++;
                vector<pair<int, int>> zero;
                queue<pair<int, int>> bfs;
                bfs.push({i, j});
                visit[i][j] = 1;
                while(!bfs.empty()) {
                    int a, b;
                    tie(a, b) = bfs.front();
                    zero.push_back(bfs.front());
                    bfs.pop();
                    for(int d=0; d<4; d++) {
                        int x=a+dx[d];
                        int y=b+dy[d];
                        if(x<1||x>n||y<1||y>m) continue;
                        if(an[x][y]!='0') continue;
                        if(visit[x][y]) continue;
                        visit[x][y] = 1;
                        bfs.push({x, y});
                    }
                }
                int cnt=zero.size();
                for(auto aut : zero) {
                    poss[aut.first][aut.second] = cnt;
                    team[aut.first][aut.second] = teams;
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(an[i][j]=='a') {
                int sum=1;
                vector<int> finding;
                for(int d=0; d<4; d++) {
                    int x=i+dx[d];
                    int y=j+dy[d];
                    auto it = find(finding.begin(), finding.end(), team[x][y]);
                    if(it != finding.end()) continue;
                    if(x<1||x>n||y<1||y>m) continue;
                    if(an[x][y]=='a') continue;
                    finding.push_back(team[x][y]);
                    sum = sum+poss[x][y];
                }
                sum %= 10;
                ans[i][j] = sum;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}