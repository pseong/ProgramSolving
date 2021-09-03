#include <iostream>
#include <cstring>
#include <array>

using namespace std;

int n;
int dx[]{0, 0, -1, 1};
int dy[]{-1, 1, 0, 0};
int ans=0;

void func(int cnt, array<array<int, 25>, 25> &input_map) {
    if(cnt > 5) {
        return;
    }
    for(int d=0; d<4; d++) {
        array<array<int, 25>, 25> map(input_map);
        bool merge[25][25]{0};
        if(d==0) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(map[i][j]==0) continue;
                    int x=i;
                    int y=j;
                    while(true) {
                        int a=x+dx[d];
                        int b=y+dy[d];
                        if(a<1||a>n||b<1||b>n) break;
                        if(map[x][y]==map[a][b]) {
                            if(!merge[a][b]) {
                                map[a][b] *= 2;
                                map[x][y] = 0;
                                ans = max(ans, map[a][b]);
                                merge[a][b] = true;
                            }
                            break;
                        }
                        else if(map[a][b]==0) {
                            map[a][b] = map[x][y];
                            map[x][y] = 0;
                        }
                        else break;
                        x += dx[d];
                        y += dy[d];
                    }
                }
            }
        }
        else if(d==1) {
            for(int i=1; i<=n; i++) {
                for(int j=n; j>=1; j--) {
                    if(map[i][j]==0) continue;
                    int x=i;
                    int y=j;
                    while(true) {
                        int a=x+dx[d];
                        int b=y+dy[d];
                        if(a<1||a>n||b<1||b>n) break;
                        if(map[x][y]==map[a][b]) {
                            if(!merge[a][b]) {
                                map[a][b] *= 2;
                                ans = max(ans, map[a][b]);
                                map[x][y] = 0;
                                merge[a][b] = true;
                            }
                            break;
                        }
                        else if(map[a][b]==0) {
                            map[a][b] = map[x][y];
                            map[x][y] = 0;
                        }
                        else break;
                        x += dx[d];
                        y += dy[d];
                    }
                }
            }
        }
        else if(d==2) {
            for(int j=1; j<=n; j++) {
                for(int i=1; i<=n; i++) {
                    if(map[i][j]==0) continue;
                    int x=i;
                    int y=j;
                    while(true) {
                        int a=x+dx[d];
                        int b=y+dy[d];
                        if(a<1||a>n||b<1||b>n) break;
                        if(map[x][y]==map[a][b]) {
                            if(!merge[a][b]) {
                                map[a][b] *= 2;
                                ans = max(ans, map[a][b]);
                                map[x][y] = 0;
                                merge[a][b] = true;
                            }
                            break;
                        }
                        else if(map[a][b]==0) {
                            map[a][b] = map[x][y];
                            map[x][y] = 0;
                        }
                        else break;
                        x += dx[d];
                        y += dy[d];
                    }
                }
            }
        }
        else if(d==3) {
            for(int j=1; j<=n; j++) {
                for(int i=n; i>=1; i--) {
                    if(map[i][j]==0) continue;
                    int x=i;
                    int y=j;
                    while(true) {
                        int a=x+dx[d];
                        int b=y+dy[d];
                        if(a<1||a>n||b<1||b>n) break;
                        if(map[x][y]==map[a][b]) {
                            if(!merge[a][b]) {
                                map[a][b] *= 2;
                                ans = max(ans, map[a][b]);
                                map[x][y] = 0;
                                merge[a][b] = true;
                            }
                            break;
                        }
                        else if(map[a][b]==0) {
                            map[a][b] = map[x][y];
                            map[x][y] = 0;
                        }
                        else break;
                        x += dx[d];
                        y += dy[d];
                    }
                }
            }
        }
        func(cnt+1, map);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    array<array<int, 25>, 25> map;
    for(int i=0; i<25; i++) {
        for(int j=0; j<25; j++) {
            map[i][j] = 0;
        }
    }
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> map[i][j];
            ans = max(ans, map[i][j]);
        }
    }
    func(1, map);
    cout << ans;
}