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

struct Edge {
    int x, y, c, f;
    Edge* rev;
};

vector<Edge*> adj[20202];
int n, m;
int s, t;
Edge* d[20202];

int maxFlow() {
    int ans = 0;
    while (true) {
        memset(d, 0, sizeof d);
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<(int)adj[x].size(); i++) {
                Edge* e = adj[x][i];
                if (d[e->y] == 0 && e->c - e->f > 0) {
                    d[e->y] = e;
                    q.push(e->y);
                }
            }
        }
        if (d[t] == 0) break;
        int flow = INT_MAX;
        for (int x=t; x!=s; x=d[x]->x) {
            flow = min(flow, d[x]->c - d[x]->f);
        }
        for (int x=t; x!=s; x=d[x]->x) {
            d[x]->f += flow;
            d[x]->rev->f -= flow;
        }
        ans += flow;
    }
    return ans;
}

int conv(int x, int y) {
    return x*m + y + 1;
}

pi rev(int x) {
    x--;
    return {x/n, x%n};
}

int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};

void solve(int CASE) {
    cin >> n >> m;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 'K') {
                s = conv(i, j);
                s += 10000;
                for (int d=0; d<4; d++) {
                    int a = i+dx[d];
                    int b = j+dy[d];
                    if (a < 0 || a >= n || b < 0 || b >= m) continue;
                    if (v[a][b] == 'H') {
                        cout << -1 << '\n';
                        return;
                    }
                }
            }
            if (v[i][j] == 'H') {
                t = conv(i, j);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x = conv(i, j);
            if (v[i][j] == '#') {
                Edge* a = new Edge({x, x+10000, 0, 0});
                Edge* b = new Edge({x+10000, x, 0, 0});
                a->rev = b;
                b->rev = a;

                adj[x].push_back(a);
                adj[x+10000].push_back(b);
            }
            else {
                Edge* a = new Edge({x, x+10000, 1, 0});
                Edge* b = new Edge({x+10000, x, 0, 0});
                a->rev = b;
                b->rev = a;

                adj[x].push_back(a);
                adj[x+10000].push_back(b);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x = conv(i, j);
            for (int d=0; d<4; d++) {
                int a = i+dx[d];
                int b = j+dy[d];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                int y = conv(a, b);
                Edge* u = new Edge({x+10000, y, 1, 0});
                Edge* v = new Edge({y, x+10000, 0, 0});
                u->rev = v;
                v->rev = u;

                adj[x+10000].push_back(u);
                adj[y].push_back(v);
            }
        }
    }
    cout << maxFlow() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t=0; t<T; t++) {
        solve(t);
    }
}