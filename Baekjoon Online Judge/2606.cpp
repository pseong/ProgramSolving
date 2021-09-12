#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    vector<int> v[101];
    int n, k;
    cin >> n >> k;
    while(k--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int visit[101]{0};
    queue<int> bfs;
    visit[1]=1;
    bfs.push(1);
    int ans=-1;
    while(!bfs.empty()) {
        int x = bfs.front();
        bfs.pop();
        ans++;
        for(int y : v[x]) {
            if(visit[y]) continue;
            visit[y] = 1;
            bfs.push(y);
        }
    }
    cout << ans;
}