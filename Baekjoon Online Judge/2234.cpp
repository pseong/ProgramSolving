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

int c[10000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    int idx = 0;
    vector<vector<int>> chk(n + 1, vector<int>(m + 1));
    int mx = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (chk[i][j] == 0) {
                idx++;
                chk[i][j] = idx;
                queue<pi> q;
                q.push({i, j});
                int cnt = 0;
                while (q.size()) {
                    cnt++;
                    auto [x, y] = q.front();
                    q.pop();
                    int dx[] {0, -1, 0, 1};
                    int dy[] {-1, 0, 1, 0};
                    for (int d=0; d<4; d++) {
                        if (v[x][y] & (1<<d)) continue;
                        int a = x + dx[d];
                        int b = y + dy[d];
                        if (a < 1 || a > n || b < 1 || b > m) continue;
                        if (chk[a][b]) continue;
                        chk[a][b] = idx;
                        q.push({a, b});
                    }
                }
                c[idx] = cnt;
                mx = max(mx, cnt);
            }
        }
    }
    int ans = 0;
    for (int i=1; i<n; i++) {
        for (int j=1; j<=m; j++) {
            if (chk[i][j] == chk[i+1][j]) continue;
            ans = max(ans, c[chk[i][j]] + c[chk[i+1][j]]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<m; j++) {
            if (chk[i][j] == chk[i][j+1]) continue;
            ans = max(ans, c[chk[i][j]] + c[chk[i][j+1]]);
        }
    }
    cout << idx << '\n' << mx << '\n' << ans << '\n';
}