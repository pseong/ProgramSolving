#include <iostream>
#include <queue>

using namespace std;

int visit[100001]{0};
int dist[100001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> bfs;
    visit[n]=1;
    bfs.push(n);
    while(!bfs.empty()) {
        if(visit[k]) break;
        int x = bfs.front();
        bfs.pop();
        if(x-1>=0 && !visit[x-1]) {
            dist[x-1] = dist[x]+1;
            visit[x-1] = 1;
            bfs.push(x-1);
        }
        if(x+1<=100000 && !visit[x+1]) {
            dist[x+1] = dist[x]+1;
            visit[x+1] = 1;
            bfs.push(x+1);
        }
        if(x*2<=100000 && !visit[x*2]) {
            dist[x*2] = dist[x]+1;
            visit[x*2] = 1;
            bfs.push(x*2);
        }
    }
    cout << dist[k];
}