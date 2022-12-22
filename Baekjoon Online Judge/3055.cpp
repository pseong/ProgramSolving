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
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> w(n, vector<int>(m, 1e9));
    queue<pi> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == '*') {
                q.push({i, j});
                w[i][j] = 0;
            }
        }
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d=0; d<4; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (v[a][b] != '.' || w[a][b] != 1e9) continue;
            w[a][b] = w[x][y] + 1;
            q.push({a, b});
        }
    }
    vector<vector<int>> p(n, vector<int>(m, -1));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 'S') {
                q.push({i, j});
                p[i][j] = 0;
            }
        }
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d=0; d<4; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (v[a][b] == 'D') {
                cout << p[x][y] + 1 << '\n';
                return 0;
            }
            if (p[a][b] != -1 || v[a][b] != '.' || p[x][y] + 1 >= w[a][b]) continue;
            p[a][b] = p[x][y] + 1;
            q.push({a, b});
        }
    }
    cout << "KAKTUS\n";
}