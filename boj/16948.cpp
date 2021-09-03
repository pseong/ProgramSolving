#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[]{-2,-2,0,0,2,2};
int dy[]{-1,1,-2,2,-1,1};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int siz;
    cin >> siz;
    int an[201][201]{0};

    int x, y, a, b;
    cin >> x >> y >> a >> b;
    x++; y++; a++; b++;
    int ans=-1;
    queue<tuple<int ,int, int>> bfs;
    bfs.push({x, y, 0});
    int visit[201][201]{0};
    visit[x][y] = 1;
    while(!bfs.empty()) {
        if(ans!=-1) break;
        int i, j, cnt;
        tie(i, j, cnt) = bfs.front();
        bfs.pop();
        for(int d=0; d<6; d++) {
            int n=i+dx[d];
            int m=j+dy[d];
            if(n<1||n>siz||m<1||m>siz) continue;
            if(visit[n][m]) continue;
            visit[n][m] = 1;
            bfs.push({n,m,cnt+1});
            if(n==a&&m==b) {
                ans = cnt+1;
                break;
            }
        }
    }
    cout << ans;
}