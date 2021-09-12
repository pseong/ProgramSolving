#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
pair<int, int> p[10001];
vector<int> level[10001];
int index=1;

void dfs(int node, int depth) {
    int a, b;
    tie(a, b) = p[node];
    if(a!=-1) dfs(a, depth+1);
    level[depth].push_back(index);
    index++;
    if(b!=-1) dfs(b, depth+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int check_root[10001]{0};
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(b!=-1) check_root[b]=1;
        if(c!=-1) check_root[c]=1;
        p[a] = {b, c};
    }

    int root=1;
    for(int i=1; i<=n; i++) {
        if(check_root[i]==0) {
            root = i;
        }
    }

    dfs(root, 1);
    int ans=1;
    int ans_level=1;
    for(int i=1; level[i].size()>0; i++) {
        sort(level[i].begin(), level[i].end());
        int res = level[i][level[i].size()-1] - level[i][0] + 1;
        if(ans<res) {
            ans = res;
            ans_level = i;
        }
    }

    cout << ans_level << ' ' << ans;
}