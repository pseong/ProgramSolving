#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[150000]; //정점 그래프
int visit[150000]{0}; //visit[x] : x노드의 깊이 + 1 (0은 방문하지 않음으로 처리하기 위해 +1 추가)
int input[150000]{0};
int order[150000]{0};

bool func(int a, int b) {
    return order[a] < order[b];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n; i++) {
        cin >> input[i];
        order[input[i]] = i;
    }

    for(int i=0; i<n; i++) {
        sort(v[i].begin(), v[i].end(), func);
    }

    queue<int> bfs;
    visit[1] = 1;
    bfs.push(1);
    int index=0;
    int ans=1;
    while(!bfs.empty()) {
        int vert = bfs.front();
        bfs.pop();
        if(input[index] != vert) {
            ans=0;
            break;
        }
        index++;
        for(int node : v[vert]) {
            if(visit[node]) continue;
            visit[node] = 1;
            bfs.push(node);
        }
    }
    cout << ans;
    return 0;
}