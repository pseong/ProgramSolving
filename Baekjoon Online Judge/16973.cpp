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

int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

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
    int h, w, sr, sc, fr, fc;
    cin >> h >> w >> sr >> sc >> fr >> fc;
    queue<pi> q;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, 1e9));
    q.push({sr, sc});
    dist[sr][sc] = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d=0; d<4; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            bool ok = true;
            if (d == 0) {
                for (int j=b; j<=b+w-1; j++) {
                    if (a < 1 || a > n || j < 1 || j > m || v[a][j]) ok = false;
                }
            }
            else if (d == 1) {
                for (int j=b; j<=b+w-1; j++) {
                    if (a + h - 1 < 1 || a + h -1  > n || j < 1 || j > m || v[a + h -1][j]) ok = false;
                }
            }
            else if (d == 2) {
                for (int i=a; i<=a+h-1; i++) {
                    if (i < 1 || i > n || b < 1 || b > m || v[i][b]) ok = false;
                }
            }
            else if (d == 3) {
                for (int i=a; i<=a+h-1; i++) {
                    if (i < 1 || i > n || b + w - 1 < 1 || b + w - 1 > m || v[i][b + w - 1]) ok = false;
                }
            }
            if (!ok) continue;
            if (dist[a][b] != 1e9) continue;
            dist[a][b] = dist[x][y] + 1;
            q.push({a, b});
        }
    }
    if (dist[fr][fc] == 1e9) cout << -1 << '\n';
    else cout << dist[fr][fc] << '\n';
}