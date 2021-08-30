#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int d[100001]{0};
bool visit[100001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    d[n] = 0;
    visit[n] = true;
    deque<int> bfs;
    bfs.push_back(n);
    while(!bfs.empty()) {
        int a = bfs.front();
        bfs.pop_front();
        if(a*2<=100000 && !visit[a*2]) {
            visit[a*2]=true;
            d[a*2] = d[a];
            bfs.push_front(a*2);
        }
        if(a-1>=0 && !visit[a-1]) {
            visit[a-1]=true;
            d[a-1] = d[a]+1;
            bfs.push_back(a-1);
        }
        if(a+1<=100000 && !visit[a+1]) {
            visit[a+1]=true;
            d[a+1] = d[a]+1;
            bfs.push_back(a+1);
        }
    }
    cout << d[k];
}