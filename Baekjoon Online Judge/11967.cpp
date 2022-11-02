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

int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<vector<pi>>> v(n + 1, vector<vector<pi>>(n + 1, vector<pi>()));
    vector<vector<int>> chk(n + 1, vector<int>(n + 1));
    vector<vector<int>> poss(n + 1, vector<int>(n + 1));
    for (int i=0; i<m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        v[a][b].push_back({x, y});
    }
    queue<pi> q;
    q.push({1, 1});
    chk[1][1] = 1;
    poss[1][1] = 1;
    while (q.size()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        for (int d=0; d<4; d++) {
            int x = a + dx[d];
            int y = b + dy[d];
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (chk[x][y] || !poss[x][y]) continue;
            chk[x][y] = 1;
            q.push({x, y});
        }
        for (auto [x, y] : v[a][b]) {
            if (chk[x][y] || poss[x][y]) continue;
            poss[x][y] = 1;
            bool ok = false;
            for (int dd=0; dd<4; dd++) {
                int r = x + dx[dd];
                int c = y + dy[dd];
                if (r < 1 || r > n || c < 1 || c > n) continue;
                if (chk[r][c] == 1) ok = true;
            }
            if (ok) {
                chk[x][y] = 1;
                q.push({x, y});
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (poss[i][j] == 1) ans++;
        }
    }
    cout << ans << '\n';
}