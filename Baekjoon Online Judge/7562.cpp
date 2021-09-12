#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;

int dx[8]{-1, -1, -2, -2, 1, 1, 2, 2};
int dy[8]{-2, 2, -1, 1, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        queue<tuple<int, int, int>> bfs;
        int visit[300][300]{0};

        cin >> n;
        int x, y;
        cin >> x >> y;
        bfs.push({x, y, 0});
        cin >> x >> y;
        int last_x = x;
        int last_y = y;

        int ans=-1;
        while(!bfs.empty()) {
            auto now = bfs.front(); bfs.pop();
            if(get<0>(now)==last_x && get<1>(now)==last_y) {
                ans = get<2>(now);
                break;
            }

            for(int i=0; i<8; i++) {
                int x = get<0>(now) + dx[i];
                int y = get<1>(now) + dy[i];
                int cnt = get<2>(now);

                if(x<0 || x>n-1 || y<0 || y>n-1) continue;
                if(visit[x][y]) continue;

                visit[x][y] = 1;
                bfs.push({x, y, cnt+1});
            }
        }
        cout << ans << '\n';
    }
}