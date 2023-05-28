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

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) adj[i].clear();
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (adj[i].size() < 4) continue;
        vector<int> hist(n + 1, -1), color(n + 1, -1);
        queue<int> q;
        color[i] = 0;
        hist[i] = 0;
        int c = 1;
        for (int y : adj[i]) {
            color[y] = c;
            hist[y] = i;
            q.push(y);
            c++;
        }
        int cycle[2]{0, 0};
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (color[y] == color[x] || y == i) continue;
                if (color[y] != -1 && color[y] != color[x]) {
                    cycle[0] = x;
                    cycle[1] = y;
                    goto g;
                }
                hist[y] = x;
                color[y] = color[x];
                q.push(y);
            }
        }
        continue;
        g:
        yes();
        vector<pi> ans;
        ans.push_back({cycle[0], cycle[1]});
        int nxt[2];
        int go = cycle[0];
        while (go != i) {
            ans.push_back({go, hist[go]});
            if (hist[go] == i) nxt[0] = go;
            go = hist[go];
        }
        go = cycle[1];
        while (go != i) {
            ans.push_back({go, hist[go]});
            if (hist[go] == i) nxt[1] = go;
            go = hist[go];
        }
        int cnt = 0;
        for (int y : adj[i]) {
            if (y != nxt[0] && y != nxt[1]) {
                ans.push_back({i, y});
                cnt++;
            }
            if (cnt == 2) break;
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
        return;
    }
    no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}