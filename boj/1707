#include <bits/stdc++.h>

using namespace std;

vector<int> edges[20010];
int colored[20010]{ 0 };
bool binary_graph = 1;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int k;
    cin >> k;
    while(k--) {
        int v, e;
        cin >> v >> e;
        for(int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        for(int i = 1; i <= v; i++) {
            if(colored[i] || !binary_graph) continue;
            queue<int> que;
            que.push(i);
            colored[i] = 1;
            while(!que.empty() && binary_graph) {
                int a = que.front();
                que.pop();
                int color = (colored[a] == 1) ? 2 : 1;
                for(int i : edges[a]) {
                    if(colored[i]) {
                        if(colored[i] != color) {
                            binary_graph = 0;
                            break;
                        }
                    }
                    else {
                        colored[i] = color;
                        que.push(i);
                    }
                }
            }
        }
        cout << (binary_graph ? "YES\n" : "NO\n");

        for(int i = 1; i <= v; i++) {
            colored[i] = 0;
            edges[i].clear();
            binary_graph = 1;
        }
    }
}