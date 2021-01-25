#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1010];
bool visited[1010]{ 0 };

void dfs(int s) {
    if(visited[s]) return;
    cout << s << ' ';
    visited[s] = 1;
    for(int a : adj[s])
        dfs(a);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
        
    dfs(v);
    cout << '\n';

    for(int i = 1; i <= n; i++)
        visited[i] = 0;

    queue<int> que;
    que.push(v);

    while(!que.empty()) {
        int a = que.front();
        que.pop();
        if(!visited[a]) {
            cout << a << ' ';
            visited[a] = 1;
            for(int i : adj[a])
                que.push(i);
        }
    }
}