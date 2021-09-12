#include <iostream>

using namespace std;

char map[21][21]{0};
int start1[2]{0};
int start2[2]{0};
int visit[21][21][21][21]{0};
int n, m;

int dx[4]{-1, 1, 0, 0};
int dy[4]{0, 0, -1, 1};

bool check(int x, int y) {
    if(x>=1 && x<=n && y>=1 && y<=m) return true;
    else return false;
}

int ans=-1;
void func(int num, int x1, int y1, int x2, int y2) {
    if(num>=10) return;
    for(int i=0; i<4; i++) {
        int a1=x1+dx[i];
        int b1=y1+dy[i];
        if(map[a1][b1]=='#') {
            a1=x1;
            b1=y1;
        }
        int a2=x2+dx[i];
        int b2=y2+dy[i];
        if(map[a2][b2]=='#') {
            a2=x2;
            b2=y2;
        }
        if(visit[a1][b1][a2][b2]) continue;
        if(!check(a1, b1) && !check(a2, b2)) continue;
        if(check(a1, b1) && !check(a2, b2) ||
            !check(a1, b1) && check(a2, b2)) {
                if(ans==-1) ans = num+1;
                else ans = min(ans, num+1);
            }
        else {
            visit[a1][b1][a2][b2] = 1;
            func(num+1, a1, b1, a2, b2);
            visit[a1][b1][a2][b2] = 0;
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
            cin >> map[i][j];
            if(map[i][j] == 'o') {
                if(start1[0]) {
                    start2[0] = i;
                    start2[1] = j;
                } else {
                    start1[0] = i;
                    start1[1] = j;
                }
            }
        }
    }
    visit[start1[0]][start1[1]][start2[0]][start2[1]] = 1;
    func(0, start1[0], start1[1], start2[0], start2[1]);
    cout << ans;
    return 0;
}