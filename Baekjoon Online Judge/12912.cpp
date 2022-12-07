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

vector<pi> adj[2020];
int X, Y, maxN;
ll maxC;

void dfs(int x, int p, ll c) {
    if (maxC <= c) {
        maxC = c;
        maxN = x;
    }
    for (auto [y, c2] : adj[x]) {
        if (y == p) continue;
        if (x == X && y == Y || x == Y && y == X) continue;
        dfs(y, x, c + c2);
    }
}

ll getD(int x) {
    maxC = 0;
    dfs(x, 0, 0);
    maxC = 0;
    dfs(maxN, 0, 0);
    return maxC;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ti> edges;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++;
        b++;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        edges.push_back({a, b, c});
    }
    ll ans = 0;
    for (auto [a, b, c] : edges) {
        X = a, Y = b;
        ll sum = getD(a) + getD(b) + c;
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}