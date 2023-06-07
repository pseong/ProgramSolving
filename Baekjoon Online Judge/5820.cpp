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

int n, k;
vector<pi> adj[202020];
int sz[202020], cent[202020];
const int inf = 1e9;
int ans = inf;
int mp[1010101], mp2[1010101];
vector<int> ass, as;

ll get_sz(int x, int p) {
    sz[x] = 1;
    for (auto [y, c] : adj[x]) {
        if (y == p || cent[y]) continue;
        sz[x] += get_sz(y, x);
    }
    return sz[x];
}

int get_cent(int x, int p, int all) {
    for (auto [y, c] : adj[x]) {
        if (y == p || cent[y]) continue;
        if (sz[y]*2 > all) return get_cent(y, x, all);
    }
    return x;
}

void dfs(int x, int p, int depth, int dist) {
    if (dist > k) return;
    mp2[dist] = min(mp2[dist], depth);
    ass.push_back(dist);
    for (auto [y, c] : adj[x]) {
        if (y == p || cent[y]) continue;
        dfs(y, x, depth + 1, dist + c);
    }
}

void go(int x) {
    for (int d : as) mp[d] = inf;
    as.clear();

    for (auto [y, c] : adj[x]) {
        if (cent[y]) continue;
        dfs(y, x, 1, c);
        ass.push_back(0);
        mp2[0] = 0;
        for (int d : ass) {
            as.push_back(d);
            ans = min(ans, mp2[d] + mp[k-d]);
        }
        for (int d : ass) {
            mp[d] = min(mp[d], mp2[d]);
            mp2[d] = inf;
        }
        ass.clear();
    }

    for (auto [y, c] : adj[x]) {
        if (cent[y]) continue;
        get_sz(y, -1);
        int s = get_cent(y, -1, sz[y]);
        cent[s] = 1;
        go(s);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for (int i=0; i<=k; i++) mp2[i] = inf;
    for (int i=0; i<=k; i++) mp[i] = inf;

    get_sz(1, -1);
    int s = get_cent(1, -1, sz[1]);
    cent[s] = 1;
    go(s);

    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}