#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int an[110][110]{0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> an[i][j];
        }
    }

    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};
    int ans=0;
    while(true) {
        bool finish=true;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(an[i][j]==-1) {
                    an[i][j] = 0;
                } else if(an[i][j]>=3) {
                    an[i][j] = 0;
                } else if(an[i][j]==2) {
                    an[i][j] = 1;
                    finish = false;
                } else if(an[i][j]==1) {
                    finish = false;
                }
            }
        }
        if(finish) break;
        ans++;

        queue<pii> bfs;
        bfs.push({1, 1});
        an[1][1] = -1;
        while(!bfs.empty()) {
            int a, b;
            tie(a, b) = bfs.front();
            bfs.pop();
            for(int d=0; d<4; d++) {
                int x=a+dx[d];
                int y=b+dy[d];
                if(x<1||x>n||y<1||y>m) continue;
                if(an[x][y]==-1) continue;
                if(an[x][y]>0) {
                    an[x][y]++;
                    continue;
                }
                if(an[x][y]==0) {
                    an[x][y] = -1;
                    bfs.push({x, y});
                }
            }
        }
    }
    cout << ans;
}