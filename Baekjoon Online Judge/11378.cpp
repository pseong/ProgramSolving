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

vector<int> adj[2020];
int c[2020][2020], f[2020][2020], d[2020];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int s = 2002;
    int b = 2003;
    int e = 2004;
    for (int i=1; i<=n; i++) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int a;
            cin >> a;
            a += 1000;
            adj[i].push_back(a);
            adj[a].push_back(i);
            c[i][a] = 1;
        }
        adj[s].push_back(i);
        adj[i].push_back(s);
        c[s][i] = 1;
        adj[b].push_back(i);
        adj[i].push_back(b);
        c[b][i] = k;
    }
    for (int i=1001; i<=1000+m; i++) {
        adj[i].push_back(e);
        adj[e].push_back(i);
        c[i][e] = 1;
    }
    adj[s].push_back(b);
    adj[b].push_back(s);
    c[s][b] = k;

    int ans = 0;
    while (true) {
        memset(d, -1, sizeof d);
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    d[y] = x;
                    q.push(y);
                    if (y == e) break;
                }
            }
        }
        if (d[e] == -1) break;
        int flow = 1000000000;
        for (int i=e; i!=s; i=d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        for (int i=e; i!=s; i=d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        ans += flow;
    }
    ans = 0;
    for (int i=1; i<=n; i++) {
        ans += f[s][i];
    }
    ans += f[s][b];
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}