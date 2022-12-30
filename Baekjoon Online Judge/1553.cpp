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

int n, m, ans, v[8][7], chk[28], chk2[8][7];
vector<pi> w;
int dx[] {1, 0};
int dy[] {0, 1};

void go(int x, int y) {
    if (y == m) {
        y = 0;
        x++;
        if (x == n) {
            ans++;
            return;
        }
    }
    if (chk2[x][y]) {
        go(x, y + 1);
        return;
    }
    for (int i=0; i<28; i++) {
        if (chk[i]) continue;
        if (w[i].first == v[x][y] || w[i].second == v[x][y]) {
            if (w[i].second == v[x][y]) swap(w[i].first, w[i].second);
            for (int d=0; d<2; d++) {
                int a = x + dx[d];
                int b = y + dy[d];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (chk2[a][b] || v[a][b] != w[i].second) continue;
                chk2[x][y] = 1;
                chk2[a][b] = 1;
                chk[i] = 1;
                go(x, y + 1);
                chk2[x][y] = 0;
                chk2[a][b] = 0;
                chk[i] = 0;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    n = 8;
    m = 7;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            v[i][j] = s[j] - '0';
        }
    }
    for (int i=0; i<=6; i++) {
        for (int j=i; j<=6; j++) {
            w.push_back({i, j});
        }
    }
    go(0, 0);
    cout << ans << '\n';
}