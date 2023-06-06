#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

int n, parent[101010][20], d[101010];
vector<int> adj[101010];

void dfs(int x, int p, int depth) {
    d[x] = depth;
    parent[x][0] = p;
    for (int y : adj[x]) {
        if (y == p) continue;
        dfs(y, x, depth + 1);
    }
}

void precal_lca() {
    dfs(1, 0, 0);
    for (int j=1; j<20; j++) {
        for (int i=1; i<=n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i=19; i>=0; i--) {
        if (d[x] - d[y] >= (1<<i)) x = parent[x][i];
    }

    if (x == y) return x;

    for (int i=19; i>=0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[y][0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    precal_lca();

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}