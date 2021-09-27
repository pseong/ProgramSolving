#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int parent[10]{0};

int getParent(int i) {
    if(parent[i]==i) return i;
    return parent[i] = getParent(parent[i]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a<b) {
        parent[b] = a;
    } else if(a>b) {
        parent[a] = b;
    }
}

int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int an[11][11]{0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> an[i][j];
            if(an[i][j]==1) an[i][j] = -1;
        }
    }
    for(int i=0; i<=m; i++) {
        parent[i] = i;
    }
    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};
    int mark=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(an[i][j]==-1) {
                queue<pair<int, int>> bfs;
                bfs.push({i, j});
                an[i][j] = mark;
                while(!bfs.empty()) {
                    int a, b;
                    tie(a, b) = bfs.front();
                    bfs.pop();
                    for(int d=0; d<4; d++) {
                        int u=a+dx[d];
                        int v=b+dy[d];
                        if(u<1||u>n||v<1||v>m) continue;
                        if(an[u][v]!=-1) continue;
                        an[u][v] = mark;
                        bfs.push({u, v});
                    }
                }
                mark++;
            }
        }
    }
    mark--;
    vector<tuple<int, int, int>> edges;
    for(int i=1; i<=n; i++) {
        int pre=-1;
        int prepos=-1;
        for(int j=1; j<=m; j++) {
            if(an[i][j]!=0) {
                if(pre==-1) pre = an[i][j];
                else if(j-prepos>1) {
                    edges.push_back({j-prepos, pre, an[i][j]});
                }
                pre = an[i][j];
                while(j<=m&&an[i][j]!=0) j++;
                prepos = j;
            }
        }
    }
    for(int j=1; j<=m; j++) {
        int pre=-1;
        int prepos=-1;
        for(int i=1; i<=n; i++) {
            if(an[i][j]!=0) {
                if(pre==-1) pre = an[i][j];
                else if(i-prepos>1) {
                    edges.push_back({i-prepos, pre, an[i][j]});
                }
                pre = an[i][j];
                while(i<=n&&an[i][j]!=0) i++;
                prepos = i;
            }
        }
    }
    sort(edges.begin(), edges.end());
    int cnt=0;
    int ans=0;
    for(int i=0; i<edges.size(); i++) {
        if(cnt==mark-1) break;
        int a, b, c;
        tie(c, a, b) = edges[i];
        if(findParent(a, b)) continue;
        unionParent(a, b);
        ans += c;
        cnt++;
    }
    if(cnt!=mark-1) {
        cout << -1;
    } else {
        cout << ans;
    }
}