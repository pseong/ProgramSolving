#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int degree[10010]{0};
int depth[10010]{0};
vector<int> v[10010];
void dfs(int node, int d) {
    depth[node] = d;
    for(int i : v[node]) {
        dfs(i, d+1);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int parent[10010]{0};
        int degree[10010]{0};
        int root=0;
        for(int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
            v[a].push_back(b);
        }
        for(int i=1; i<n; i++) {
            if(parent[i]==0) {
                root = i;
                break;
            }
        }
        dfs(root, 0);
        int a, b;
        cin >> a >> b;
        if(depth[a]<depth[b]) swap(a, b);

        while(depth[a]!=depth[b]) {
            a = parent[a];
        }
        while(a!=b) {
            a = parent[a];
            b = parent[b];
        }
        cout << a << '\n';
        memset(degree, 0, sizeof(degree));
        memset(depth, 0, sizeof(depth));
        for(int i=1; i<=n; i++) {
            v[i].clear();
        }
    }
}