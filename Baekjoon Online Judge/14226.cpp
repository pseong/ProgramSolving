#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>

using namespace std;
int d[1001][1001];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int s;
    cin >> s;

    queue<pair<int, int>> bfs;
    memset(d,-1,sizeof(d));
    bfs.push({1,0});
    d[1][0] = 0;
    while(!bfs.empty()) {
        int a, b;
        tie(a, b) = bfs.front();
        bfs.pop();
        if (d[a][a] == -1) {
            d[a][a] = d[a][b] + 1;
            bfs.push({a, a});
        }
        if (a+b<=1000 && d[a+b][b] == -1) {
            d[a+b][b] = d[a][b] + 1;
            bfs.push({a+b, b});
        }
        if (a-1>=0 && d[a-1][b] == -1) {
            d[a-1][b] = d[a][b] + 1;
            bfs.push({a-1, b});
        }
    }
    int ans=d[s][1];
    for(int i=2; i<=s; i++) {
        if(ans>d[s][i]) ans = d[s][i];
    }
    cout << ans;
}