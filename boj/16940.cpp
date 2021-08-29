#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[150000]; //정점 그래프
int visit[150000]{0}; //visit[x] : x노드의 깊이 + 1 (0은 방문하지 않음으로 처리하기 위해 +1 추가)
int cnt[150000]{0}; //cnt[x] : 깊이가 x인 노드의 개수
int input[150000]{0}; // 입력된 노드 순서

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
    }

    queue<int> bfs;
    bfs.push(1);
    visit[1] = 1;
    //bfs 탐색으로 모든 노드의 깊이(visit)와 깊이마다 몇개의 노드가 존재하는지(cnt)를 구함
    while(!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        cnt[visit[node]-1]++; //cnt 배열에 해당 노드 추가 
        for(int vert : v[node]) {
            if(visit[vert]) continue;
            visit[vert] = visit[node]+1;
            bfs.push(vert);
        }
    }

    int ans=1;
    int idx_input=0; // input[idx_input]로 사용
    //i : 노드의 깊이
    //i가 0인 노드부터 순차적으로 검사
    //트리에서 cnt[i]는 항상 양수이므로 cnt[i]가 0이되는 즉시 검사 종료
    for(int i=0; cnt[i]; i++) {
        while(cnt[i]--) {
            if(visit[input[idx_input]]-1!=i) ans = 0;
            idx_input++;
        }
    }
    cout << ans;
}