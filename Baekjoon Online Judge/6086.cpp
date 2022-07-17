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

int c[1010][1010], f[1010][1010], d[1010];
vector<int> adj[1010];

void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        char a, b;
        int z;
        cin >> a >> b >> z;
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] += z;
        c[b][a] += z;
    }

    int s = 'A';
    int e = 'Z';
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
                }
            }
        }
        if (d[e] == -1) break;
        int flow = 1000;
        for (int i=e; i!=s; i=d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        for (int i=e; i!=s; i=d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        ans += flow;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}