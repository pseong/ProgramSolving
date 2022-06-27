#include <bits/stdc++.h>
#define int long long
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

vector<int> adj[101010];
int s, t;
int parent[101010];
int color[101010];
vector<int> ans;
int chk[101010];

void dfs(int x, int p) {
    parent[x] = p;
    for (int y : adj[x]) {
        if (p == y) continue;
        dfs(y, x);
    }
}

int j;
bool f;
void dfs2(int x) {
    if (j >= 3) {
        chk[x] = 1;
        ans.push_back(x);
        j = 0;
    }
    int c = -1;
    for (int y : adj[x]) {
        if (y == parent[x]) continue;
        if (color[y]) {
            c = y;
            continue;
        }
        j++;
        dfs2(y);
    }
    if (!chk[x]) {
        chk[x] = 1;
        ans.push_back(x);
        j = 0;
    }
    j++;
    if (c != -1) {
        if (c == t) {
            f = true;
        }
        if (!f) j = 3;
        dfs2(c);
    }
}

void solve() {
    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s >> t;
    dfs(s, 0);
    int go = t;
    while (go != s) {
        color[go] = 1;
        go = parent[go];
    }

    chk[s] = 1;
    ans.push_back(s);
    dfs2(s);
    for (int x : ans) {
        cout << x << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}