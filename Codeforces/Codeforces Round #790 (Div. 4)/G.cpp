#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

vector<int> adj[4040];
string s;
int cnt;

int dfs(int x) {
    int ret = 0;
    for (int y : adj[x]) {
        ret += dfs(y);
    }
    ret += s[x] == 'W' ? 1 : -1;
    if (ret == 0) cnt++;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cnt = 0;
        for (int i=0; i<=n; i++) adj[i].clear();
        vector<int> p(n+1);
        for (int i=1; i<n; i++) {
            cin >> p[i];
            p[i]--;
            adj[p[i]].push_back(i);
        }
        cin >> s;
        dfs(0);
        cout << cnt << '\n';
    }
}