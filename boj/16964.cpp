#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[150000];
int visit[150000]{0};
int input[150000]{0};
int order[150000]{0};

bool func(int a, int b) {
    return order[a] < order[b];
}

int index=0;
int ans=1;
void dfs(int node) {
    if(input[index] != node) ans=0;
    index++;
    for(int vert : v[node]) {
        if(visit[vert]) continue;
        if(!ans) break;
        visit[vert] = 1;
        dfs(vert);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n; i++) {
        cin >> input[i];
        order[input[i]] = i;
    }

    for(int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end(), func);
    }

    visit[1] = 1;
    dfs(1);

    cout << ans;
    return 0;
}