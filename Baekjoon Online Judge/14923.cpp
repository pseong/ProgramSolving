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

int chk[1010][1010][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    fill(&chk[0][0][0], &chk[1009][1009][1], 1e9);
    chk[x1][y1][0] = 0;
    queue<ti> q;
    q.push({x1, y1, 0});
    while (q.size()) {
        auto [x, y, w] = q.front();
        q.pop();
        int dx[] {-1, 1, 0, 0};
        int dy[] {0, 0, -1, 1};
        for (int d=0; d<4; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            int c = w;
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (v[a][b]) c++;
            if (c >= 2) continue;
            if (chk[a][b][c] != 1e9) continue;
            chk[a][b][c] = chk[x][y][w] + 1;
            q.push({a, b, c});
        }
    }
    int ans = min(chk[x2][y2][0], chk[x2][y2][1]);
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}