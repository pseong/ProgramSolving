#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int r, c, m;
    cin >> r >> c >> m;
    tuple<int, int, int> an[101][101];
    for(int i=0; i<m; i++) {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        an[x][y] = {s, d, z};
    }
    int dx[]{0, -1, 1, 0, 0};
    int dy[]{0, 0, 0, 1, -1};
    int rev[5]{0, 2, 1, 4, 3};
    int ans=0;
    for(int row=1; row<=c; row++) {
        for(int i=1; i<=r; i++) {
            if(get<2>(an[i][row])>0) {
                ans += get<2>(an[i][row]);
                an[i][row] = {0, 0, 0};
                break;
            }
        }
        tuple<int, int, int> mv[101][101];
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=c; j++) {
                if(get<2>(an[i][j])>0) {
                    int k, d, z;
                    tie(k, d, z) = an[i][j];
                    int x=i;
                    int y=j;
                    if(d==1||d==2) {
                        k -= k/((r-1)*2)*((r-1)*2);
                    } else {
                        k -= k/((c-1)*2)*((c-1)*2);
                    }
                    for(int _=0; _<k; _++) {
                        x += dx[d];
                        y += dy[d];
                        if(x<1||x>r||y<1||y>c) {
                            d=rev[d];
                            x += dx[d];
                            y += dy[d];
                            x += dx[d];
                            y += dy[d];
                        }
                    }
                    if(get<2>(mv[x][y])>0) {
                        if(get<2>(mv[x][y]) < z) {
                            mv[x][y] = {k, d, z};
                        }
                    } else {
                        mv[x][y] = {k, d, z};
                    }
                }
            }
        }
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=c; j++) {
                an[i][j] = mv[i][j];
            }
        }
    }
    cout << ans;
}