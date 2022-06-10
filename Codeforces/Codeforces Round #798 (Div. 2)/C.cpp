#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector<int> adj[303030];
int cnt[303030];
int ans;

int dfs(int x, int p) {
    int c = 1;
    for (int y : adj[x]) {
        if (y == p) continue;
        c += dfs(y, x);
    }
    return cnt[x] = c;
}

int dfs2(int x, int p) {
    int left = -1;
    int lin = -1;
    int right = -1;
    int rin = -1;
    for (int y : adj[x]) {
        if (y == p) continue;
        if (left == -1) {
            left = y;
            lin = dfs2(y, x);
        }
        else {
            right = y;
            rin = dfs2(y, x);
        }
    }
    if (left == -1) return 0;
    if (right == -1) return cnt[left]-1;
    return max(cnt[left]+rin, cnt[right]+lin)-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i=0; i<=n; i++) {
            adj[i].clear();
            cnt[i] = 0;
            ans = 0;
        }

        for (int i=0; i<n-1; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1, 0);
        cout << dfs2(1, 0) << '\n';
    }
}