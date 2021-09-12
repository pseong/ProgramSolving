#include <iostream>
#include <cstring>

using namespace std;

bool c1[10][11]{0}; //행
bool c2[10][11]{0}; //열
bool c3[10][11]{0}; //사각형
int map[10][10]{0};
bool use[10][10]{0};
int n;

int dx[2]{1, 0};
int dy[2]{0, 1};


bool ok=false;
void func(int cnt, int x, int y) {
    if(cnt==26) {
        ok = true;
        return;
    }
    if(x==9 && y==9) return;
    if(map[x][y]) {
        if(y==9) {
            func(cnt, x+1, 1);
        } else {
            func(cnt, x, y+1);
        }
        return;
    }
    bool possible=false;
    for(int k=0; k<2; k++) {
        int a=x+dx[k];
        int b=y+dy[k];
        if(a<=9 && b<=9 && !map[a][b]) {
            possible=true;
            for(int i=1; i<=9; i++) {
                for(int j=i+1; j<=9; j++) {
                    if(use[i][j]) continue;
                    if(!(c1[x][i] || c2[y][i] || c3[(x-1)/3*3+(y-1)/3][i]) && !(c1[a][j] || c2[b][j] || c3[(a-1)/3*3+(b-1)/3][j])) {
                        //x,y에 i, a,b에 j
                        map[x][y]=i;
                        map[a][b]=j;
                        use[i][j]=true;
                        use[j][i]=true;
                        c1[x][i]=1;
                        c2[y][i]=1;
                        c3[(x-1)/3*3+(y-1)/3][i]=1;
                        c1[a][j]=1;
                        c2[b][j]=1;
                        c3[(a-1)/3*3+(b-1)/3][j]=1;
                        if(y==9) {
                            func(cnt+1, x+1, 1);
                        } else {
                            func(cnt+1, x, y+1);
                        }
                        if(ok) return;
                        map[x][y]=0;
                        map[a][b]=0;
                        use[i][j]=false;
                        use[j][i]=false;
                        c1[x][i]=0;
                        c2[y][i]=0;
                        c3[(x-1)/3*3+(y-1)/3][i]=0;
                        c1[a][j]=0;
                        c2[b][j]=0;
                        c3[(a-1)/3*3+(b-1)/3][j]=0;
                    }
                    if(!(c1[x][j] || c2[y][j] || c3[(x-1)/3*3+(y-1)/3][j]) && !(c1[a][i] || c2[b][i] || c3[(a-1)/3*3+(b-1)/3][i])) {
                        //x,y에 j, a,b에 i
                        map[x][y]=j;
                        map[a][b]=i;
                        use[i][j]=true;
                        use[j][i]=true;
                        c1[x][j]=1;
                        c2[y][j]=1;
                        c3[(x-1)/3*3+(y-1)/3][j]=1;
                        c1[a][i]=1;
                        c2[b][i]=1;
                        c3[(a-1)/3*3+(b-1)/3][i]=1;
                        if(y==9) {
                            func(cnt+1, x+1, 1);
                        } else {
                            func(cnt+1, x, y+1);
                        }
                        if(ok) return;
                        map[x][y]=0;
                        map[a][b]=0;
                        use[i][j]=false;
                        use[j][i]=false;
                        c1[x][j]=0;
                        c2[y][j]=0;
                        c3[(x-1)/3*3+(y-1)/3][j]=0;
                        c1[a][i]=0;
                        c2[b][i]=0;
                        c3[(a-1)/3*3+(b-1)/3][i]=0;
                    }   
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int count=1;
    while(true) {
        cin >> n;
        if(!n) break;
        for(int i=0; i<n; i++) {
            int a, b;
            char cc1, cc2, cc3, cc4;
            cin >> a >> cc1 >> cc2 >> b >> cc3 >> cc4;
            int i1, i2, i3, i4;
            i1 = cc1-64;
            i3 = cc3-64;
            i2 = cc2-48;
            i4 = cc4-48;
            use[a][b]=true;
            use[b][a]=true;
            map[i1][i2]=a;
            c1[i1][a]=true;
            c2[i2][a]=true;
            c3[(i1-1)/3*3+(i2-1)/3][a]=true;
            map[i3][i4]=b;
            c1[i3][b]=true;
            c2[i4][b]=true;
            c3[(i3-1)/3*3+(i4-1)/3][b]=true;
        }
        for(int i=0; i<9; i++) {
            char cc1, cc2;
            cin >> cc1 >> cc2;
            int i1, i2;
            i1 = cc1-64;
            i2 = cc2-48;
            map[i1][i2] = i+1;
            c1[i1][i+1]=true;
            c2[i2][i+1]=true;
            c3[(i1-1)/3*3+(i2-1)/3][i+1]=true;
        }
        int start_x=0;
        int start_y=0;
        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                if(!map[i][j]) {
                    start_x=i;
                    start_y=j;
                    break;
                }
            }
            if(start_x) break;
        }
        func(0, start_x, start_y);
        cout << "Puzzle " << count << '\n';
        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                cout << map[i][j];
            }
            cout << '\n';
        }
        ok=false;
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        memset(c3, 0, sizeof(c3));
        memset(map, 0, sizeof(map));
        memset(use, 0, sizeof(use));
        count++;
    }
}