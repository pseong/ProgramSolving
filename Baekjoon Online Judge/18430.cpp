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

int n, m, ans, now, v[10][10], chk[10][10];

bool ok(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 1;
    else return chk[x][y];
}

void open(int a, int b, int x, int y, int r, int c) {
    now += v[a][b] * 2 + v[x][y] + v[r][c];
    chk[a][b] = 1;
    chk[x][y] = 1;
    chk[r][c] = 1;
}

void close(int a, int b, int x, int y, int r, int c) {
    now -= v[a][b] * 2 + v[x][y] + v[r][c];
    chk[a][b] = 0;
    chk[x][y] = 0;
    chk[r][c] = 0;
}

void go(int x, int y) {
    ans = max(ans, now);
    if (y == m) {
        y = 0;
        x++;
        if (x == n) return;
    }
    go(x, y + 1);
    vector<tuple<int, int, int, int, int, int>> lst;
    lst.push_back({x, y, x - 1, y, x, y - 1});
    lst.push_back({x, y, x - 1, y, x, y + 1});
    lst.push_back({x, y, x + 1, y, x, y - 1});
    lst.push_back({x, y, x + 1, y, x, y + 1});
    for (auto [x, y, a, b, r, c] : lst) {
        if (!ok(x, y) && !ok(a, b) && !ok(r, c)) {
            open(x, y, a, b, r, c);
            go(x, y + 1);
            close(x, y, a, b, r, c);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    go(0, 0);
    cout << ans << '\n';
}