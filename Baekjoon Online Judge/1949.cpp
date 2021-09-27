#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[10010];
int dp[10010][2]{0}; //0=한경우, 1=안한경우
int w[10010]{0};

void dfs(int node, int pre) {
    dp[node][0] += w[node];
    for(int i : v[node]) {
        if(i==pre) continue;
        dfs(i, node);
        dp[node][0] += dp[i][1];
        dp[node][1] += max(dp[i][0], dp[i][1]);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> w[i];
    }
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    cout << max({dp[1][0], dp[1][1]});
}