#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    int a[11][11]{0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> tree[11][11];
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][b].push_back(c);
    }

    int yang[11][11]{0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            yang[i][j] = 5;
        }
    }

    int dx[]{-1,-1,-1,0,0,1,1,1};
    int dy[]{-1,0,1,-1,1,-1,0,1};

    while(k--) {
        vector<tuple<int, int, int>> die; // x, y, age
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int tr=tree[i][j].size()-1; tr>=0; tr--) {
                    if(yang[i][j]>=tree[i][j][tr]) {
                        yang[i][j] -= tree[i][j][tr];
                        tree[i][j][tr]++;
                    }
                    else {
                        die.push_back({i, j, tree[i][j][tr]/2});
                        tree[i][j].erase(tree[i][j].begin()+tr);
                    }
                }
            }
        }
        for(int i=0; i<die.size(); i++) {
            int a, b, c;
            tie(a, b, c) = die[i];
            yang[a][b] += c;
        }
        int addTree[11][11]{0};
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int index=0; index<tree[i][j].size(); index++) {
                    if(tree[i][j][index]%5==0) {
                        for(int d=0; d<8; d++) {
                            int a=i+dx[d];
                            int b=j+dy[d];
                            if(a<1||a>n||b<1||b>n) continue;
                            addTree[a][b]++;
                        }
                    }
                }
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int cnt=0; cnt<addTree[i][j]; cnt++) {
                    tree[i][j].push_back(1);
                }
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                yang[i][j] += a[i][j];
            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            ans += tree[i][j].size();
        }
    }

    cout << ans;
}