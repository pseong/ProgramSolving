#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[1000010];
int dp[1000010][2]{0};

void dfs(int node, int pre) {
    int res=1; //o
    int res2=0; //x
    for(int i : v[node]) {
        if(i==pre) continue;
        dfs(i, node);
        res += min(dp[i][0], dp[i][1]);
        res2 += dp[i][1];
    }
    dp[node][0] = res2;
    dp[node][1] = res;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    cout << min(dp[1][0], dp[1][1]);
}