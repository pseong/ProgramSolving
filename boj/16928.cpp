#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    int dari[101]{0};
    for(int i=1; i<=100; i++) {
        dari[i]=i;
    }
    for(int i=0; i<n+m; i++) {
        int from, to;
        cin >> from >> to;
        dari[from] = to;
    }

    int visit[101]{0};
    queue<pair<int, int>> bfs;
    bfs.push({1, 0});
    int ans=0;
    while(!bfs.empty()) {
        if(ans) break;
        int now=bfs.front().first;
        int cnt=bfs.front().second;
        bfs.pop();
        for(int i=1; i<=6; i++) {
            if(ans) break;
            int go=now+i;
            if(go>100) continue;
            if(go==100) {
                ans = cnt+1;
                break;
            }
            if(visit[go]) continue;
            visit[go] = 1;
            bool is_continue=false;
            while(go!=dari[go]) {
                go=dari[go];
                if(visit[go]) {
                    is_continue = true;
                    break;
                }
                if(go==100) {
                    ans = cnt+1;
                    is_continue = true;
                    break;
                }
                visit[go]=1;
            }
            if(is_continue) continue;
            bfs.push({go, cnt+1});
        }
    }

    cout << ans;
}