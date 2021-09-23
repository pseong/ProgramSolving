#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

typedef long long ll;
using namespace std;

vector<pair<int, int>> vert[501];
queue<int> bfs;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vert[a].push_back({b, c});
    }

    ll ans[501]{0};
    for(int i=1; i<=n; i++) {
        ans[i] = 1000000000;
    }
    ans[1] = 0;

    int visit[501]{0};
    for(int cnt=0; cnt<n; cnt++) {
        bfs.push(1);
        visit[1] = 1;
        while(!bfs.empty()) {
            int v=bfs.front();
            bfs.pop();
            for(auto a : vert[v]) {
                if(ans[v]+a.second<ans[a.first]) {
                    ans[a.first] = ans[v]+a.second;
                    if(cnt==n-1) {
                        cout << -1;
                        return 0;
                    }
                }
                if(!visit[a.first]) {
                    bfs.push(a.first);
                    visit[a.first] = 1;
                }
            }
        }
        memset(visit,0,sizeof(visit));
    }

    for(int i=2; i<=n; i++) {
        if(ans[i]==1000000000) cout << -1 << '\n';
        else cout << ans[i] << '\n';
    }
}