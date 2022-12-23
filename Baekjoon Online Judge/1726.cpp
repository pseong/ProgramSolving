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

int chk[150][150][5];
int dx[] {0, 0, 0, 1, -1};
int dy[] {0, 1, -1, 0, 0};
int go[5][2] {{0, 0}, {3, 4}, {3, 4}, {1, 2}, {1, 2}};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    memset(chk, -1, sizeof chk);
    int r, c, w;
    cin >> r >> c >> w;
    chk[r][c][w] = 0;
    queue<ti> q;
    q.push({r, c, w});
    while (q.size()) {
        auto [x, y, w] = q.front();
        q.pop();
        vector<ti> lst{{x + dx[w], y + dy[w], w}, {x + dx[w]*2, y + dy[w]*2, w}, {x + dx[w]*3, y + dy[w]*3, w}, {x, y, go[w][0]}, {x, y, go[w][1]}};
        for (auto [a, b, c] : lst) {
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (chk[a][b][c] != -1) continue;
            bool ok = true;
            int nx = x;
            int ny = y;
            while (nx != a || ny != b) {
                if (v[nx][ny] == 1) ok = false;
                nx += dx[w];
                ny += dy[w];
            }
            if (!ok) continue;
            chk[a][b][c] = chk[x][y][w] + 1;
            q.push({a, b, c});
        }
    }
    int a, b, f;
    cin >> a >> b >> f;
    cout << chk[a][b][f] << '\n';
}