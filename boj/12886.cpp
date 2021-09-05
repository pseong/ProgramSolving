#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int visit[1000][1000]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    queue<tuple<int, int, int>> bfs;
    bfs.push({a, b, c});
    bool ans=0;
    while(!bfs.empty()) {
        tie(a, b, c) = bfs.front();
        bfs.pop();
        if(a==b&&b==c) {
            ans = 1;
            break;
        }
        for(int i=0; i<3; i++) {
            int s, g, m;
            if(i==0) {
                s=a;
                g=b;
                m=c;
            }
            else if(i==1) {
                s=a;
                g=c;
                m=b;
            }
            else if(i==2) {
                s=b;
                g=c;
                m=a;
            }
            if(s!=g&&!visit[s][g]) {
                visit[s][g] = 1;
                visit[g][s] = 1;
                if(g < s) swap(s, g);
                g -= s;
                s += s;
                bfs.push({s, g, m});
            }
        }
    }
    cout << ans;
}