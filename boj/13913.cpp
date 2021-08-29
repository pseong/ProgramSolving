#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visit[100001]{0};
int dist[100001]{0};
int pre[100001]{0};

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
            pre[x-1] = x;
            bfs.push(x-1);
        }
        if(x+1<=100000 && !visit[x+1]) {
            dist[x+1] = dist[x]+1;
            visit[x+1] = 1;
            pre[x+1] = x;
            bfs.push(x+1);
        }
        if(x*2<=100000 && !visit[x*2]) {
            dist[x*2] = dist[x]+1;
            visit[x*2] = 1;
            pre[x*2] = x;
            bfs.push(x*2);
        }
    }
    cout << dist[k] << '\n';
    vector<int> route;
    route.push_back(k);
    int r=k;
    while(r!=n) {
        r = pre[r];
        route.push_back(r);
    }
    reverse(route.begin(), route.end());
    for(int v : route) {
        cout << v << ' ';
    }
}