#include <iostream>

using namespace std;

int n, m;
char a[15][15]{0};
bool visit[15][15][15][15]{0}; //red -> blue

int dx[4]{-1, 1, 0, 0};
int dy[4]{0, 0, -1, 1};
int ans=-1;

void func(int cnt, int red_x, int red_y, int blue_x, int blue_y) {
    if(cnt>10) return;
    for(int i=0; i<4; i++) {
        int red_a=red_x;
        int red_b=red_y;
        int blue_a=blue_x;
        int blue_b=blue_y;

        bool fail=false;
        bool finish=false;
        while(true) {
            red_a+=dx[i];
            red_b+=dy[i];
            blue_a+=dx[i];
            blue_b+=dy[i];
            if(red_a<1||red_a>n||red_b<1||red_b>m) {
                continue;
            }
            if(blue_a<1||blue_a>n||blue_b<1||blue_b>m) 
            {
                continue;
            }
            if(a[red_a][red_b]=='O') {
                finish = true;
            }
            else if(a[blue_a][blue_b]=='O') {
                fail=true;
            }
            if(a[red_a][red_b]=='#' && a[blue_a][blue_b]=='#') {
                red_a-=dx[i];
                red_b-=dy[i];
                blue_a-=dx[i];
                blue_b-=dy[i];
                break;
            }
            else if(a[red_a][red_b]=='#') {
                red_a-=dx[i];
                red_b-=dy[i];
                if(red_a==blue_a&&red_b==blue_b) {
                    blue_a-=dx[i];
                    blue_b-=dy[i];
                    break;
                }
            }
            else if(a[blue_a][blue_b]=='#') {
                blue_a-=dx[i];
                blue_b-=dy[i];
                if(red_a==blue_a&&red_b==blue_b) {
                    red_a-=dx[i];
                    red_b-=dy[i];
                    break;
                }
            }
        }
        if(fail) continue;
        if(finish) {
            if(ans==-1) ans = cnt;
            else ans = min(ans, cnt);
            return;
        }
        if(visit[red_a][red_b][blue_a][blue_b]) continue;
        visit[red_a][red_b][blue_a][blue_b] = 1;
        func(cnt+1, red_a, red_b, blue_a, blue_b);
        visit[red_a][red_b][blue_a][blue_b] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    int red_x;
    int red_y;
    int blue_x;
    int blue_y;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[i][j];
            if(a[i][j]=='R') {
                red_x = i;
                red_y = j;
                a[i][j]='.';
            } else if(a[i][j]=='B') {
                blue_x = i;
                blue_y = j;
                a[i][j]='.';
            }
        }
    }
    visit[red_x][red_y][blue_x][blue_y] = 1;
    func(1, red_x, red_y, blue_x, blue_y);
    cout << ans;
}