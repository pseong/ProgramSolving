#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int cnt=0;
    while(true) {
        cnt++;
        vector<int> v[510];
        int n, m;
        cin >> n >> m;
        if(n==0&&m==0) break;
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int visit[510]{0};
        int ans=0;
        for(int i=1; i<=n; i++) {
            if(visit[i]) continue;
            bool is_tree=true;
            queue<pair<int, int>> bfs;
            bfs.push({i, i});
            while(!bfs.empty()) {
                if(!is_tree) break;
                int a=bfs.front().first;
                int pre=bfs.front().second;
                bfs.pop();
                for(int b : v[a]) {
                    if(b==pre) continue;
                    if(visit[b]) {
                        is_tree=false;
                        break;
                    }
                    visit[b] = 1;
                    bfs.push({b, a});
                }
            }
            if(is_tree) ans++;
        }
        cout << "Case " << cnt << ": ";
        if(ans==0) cout << "No trees.\n";
        else if(ans==1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
    }
}