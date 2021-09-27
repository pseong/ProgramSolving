#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100];
int cnt[100]{0};

int dfs(int node, int pre) {
    int amt=0;
    for(int i : v[node]) {
        if(i==pre) continue;
        amt += dfs(i, node);
    }
    amt++;
    cnt[node] = amt;
    return amt;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, r, q;
    cin >> n >> r >> q;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(r, r);
    for(int i=0; i<q; i++) {
        int a;
        cin >> a;
        cout << cnt[a] << '\n';
    }
}