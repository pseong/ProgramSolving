#include <bits/stdc++.h>

using namespace std;

int result = 0;
int result_node = 0;
vector<pair<int, int>> adj[100010];

void dfs(int n, int dia, int pre) {
    if(result < dia) {
        result = dia;
        result_node = n;
    } 
    for(auto a : adj[n]) {
        if(a.first == pre) continue;
        dfs(a.first, dia + a.second, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dfs(1, 0, 0);
    int start = result_node;
    result_node = 0;
    result = 0;
    dfs(start, 0, 0);

    cout << result;
}