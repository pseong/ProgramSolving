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

int dx2[] {-2, -2, -1, -1, 1, 1, 2, 2};
int dy2[] {-1, 1, -2, 2, -2, 2, -1, 1};

int chk[50][250][250]{ 0 };

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, m, n;
    cin >> k >> m >> n;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    queue<ti> q;
    q.push({0, 0, 0});
    chk[0][0][0] = 1;
    while (q.size()) {
        int c, a, b;
        tie(c, a, b) = q.front();
        if (a == n - 1 && b == m - 1) {
            cout << chk[c][a][b] - 1 << '\n';
            return 0;
        }
        q.pop();
        if (c < k) {
            for (int d=0; d<8; d++) {
                int x = a + dx2[d];
                int y = b + dy2[d];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (chk[c + 1][x][y] || v[x][y] == 1) continue;
                chk[c + 1][x][y] = chk[c][a][b] + 1;
                q.push({c + 1, x, y});
            }
        }
        for (int d=0; d<4; d++) {
            int x = a + dx[d];
            int y = b + dy[d];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (chk[c][x][y] || v[x][y] == 1) continue;
            chk[c][x][y] = chk[c][a][b] + 1;
            q.push({c, x, y});
        }
    }
    cout << -1 << '\n';
}