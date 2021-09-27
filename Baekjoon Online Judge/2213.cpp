#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[10010];
int dp[10010][2]{0};
int w[10010]{0};
vector<int> trace;

void dfs(int node, int pre) {
    int res=w[node];
    int res2=0;
    for(int i : v[node]) {
        if(i==pre) continue;
        dfs(i, node);
        res += dp[i][0];
        if(dp[i][0] < dp[i][1]) {
            res2 += dp[i][1];
        } else {
            res2 += dp[i][0];
        }
    }
    dp[node][1] = res;
    dp[node][0] = res2;
}

void dfs2(int node, int pre, int include) {
    if(include) trace.push_back(node);
    for(int i : v[node]) {
        if(i==pre) continue;
        if(include) {
            dfs2(i, node, 0);
        } else {
            if(dp[i][0] < dp[i][1]) dfs2(i, node, 1);
            else dfs2(i, node, 0);
        }
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
    int a=dp[1][0];
    int b=dp[1][1];
    if(a<b) {
        cout << b << '\n';
        dfs2(1, 0, 1);
    } else {
        cout << a << '\n';
        dfs2(1, 0, 0);
    }
    sort(trace.begin(), trace.end());
    for(int i : trace) {
        cout << i << ' ';
    }
}