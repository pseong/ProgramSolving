#include <iostream>
#include <cstring>

using namespace std;

int an[51][51]{0};
int dx[]{0, 0, -1, 1};
int dy[]{-1, 1, 0, 0};
int n, m, k;

void dfs(int x, int y) {
    for(int d=0; d<4; d++) {
        int i=x+dx[d];
        int j=y+dy[d];
        if(i<1||i>n||j<1||j>m) continue;
        if(!an[i][j]) continue;
        an[i][j]=0;
        dfs(i, j);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        while(k--) {
            int a, b;
            cin >> b >> a;
            an[++a][++b] = 1;
        }

        int ans=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(an[i][j]) {
                    ans++;
                    an[i][j]=0;
                    dfs(i, j);
                }
            }
        }
        cout << ans << '\n';
        memset(an,0,sizeof(an));
    }
}