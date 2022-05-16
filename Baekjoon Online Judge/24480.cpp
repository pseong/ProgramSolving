#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int chk[101010];
vector<int> adj[101010];
int ord;
void dfs(int x) {
    chk[x] = ord;
    for (int y : adj[x]) {
        if (chk[y]) continue;
        ord++;
        dfs(y);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        sort(adj[i].rbegin(), adj[i].rend());
    }
    ord = 1;
    dfs(r);
    for (int i=1; i<=n; i++) {
        cout << chk[i] << '\n';
    }
}