#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[3001];
int visit[3001]{0};
int dist[3001]{0};

//visit
//0 : 방문하지 않은 노드
//1 : 방문했지만 사이클이 아닌 노드
//2 : 방문했지만 사이클인 노드

//res
//1~n : 사이클 시작 노드
//0 : 사이클 못찾음
//-1 : 사이클을 찾았지만, 포함하지 않음
int dfs(int node, int pre) {
    for (int vert : v[node]) {
        if(vert==pre) continue;

        int res=0;
        if(visit[vert]==1) res = vert;
        else {
            visit[vert] = 1;
            res = dfs(vert, node);
        }

        if(res==-1) return -1;
        if(res>0) {
            visit[vert] = 2;
            if(node==res) return -1;
            else return res;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    visit[1] = 1;
    dfs(1, -1);
    queue<int> bfs;
    for(int i=1; i<=n; i++) {
        if(visit[i]==2) {
            dist[i] = 0;
            bfs.push(i);
        } else {
            dist[i] = -1;
        }
    }
    while(!bfs.empty()) {
        int x=bfs.front();
        bfs.pop();
        for(int y : v[x]) {
            if(dist[y]==-1) {
                bfs.push(y);
                dist[y] = dist[x]+1;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}