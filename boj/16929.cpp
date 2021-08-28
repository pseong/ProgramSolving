#include <iostream>

using namespace std;

int n, m;
char mp[51][51]{0};
char visit[51][51]{0};

int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};

bool ans=false;

void dfs(char c, int x, int y, int dir_pre) {
    if(dir_pre==0) dir_pre=2;
    else if(dir_pre==2) dir_pre=0;
    else if(dir_pre==1) dir_pre=3;
    else if(dir_pre==3) dir_pre=1;

    for(int i=0; i<4; i++) {
        if(i==dir_pre) continue;

        int move_x = x+dx[i];
        int move_y = y+dy[i];

        if(move_x<1 || move_x>n || move_y<1 || move_y>m) continue;
        if(visit[move_x][move_y]) {
            if(visit[move_x][move_y]==c) ans = true;
        } else {
            if(mp[move_x][move_y]==c) {
                visit[move_x][move_y]=c;
                dfs(c, move_x, move_y, i);
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> mp[i][j];
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(visit[i][j]) continue; // if(visit[i][j]!='/0') continue;
            visit[i][j] = mp[i][j];
            dfs(mp[i][j], i, j, -1);
        }
    }

    cout << (ans ? "Yes" : "No");
}