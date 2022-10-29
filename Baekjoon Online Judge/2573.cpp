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
    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    int t = 0;
    while (true) {
        vector<vector<int>> chk(n, vector<int>(m));
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (chk[i][j] == 0 && v[i][j] > 0) {
                    cnt++;
                    chk[i][j] = 1;
                    queue<pi> q;
                    q.push({i, j});
                    while (q.size()) {
                        int a, b;
                        tie(a, b) = q.front();
                        q.pop();
                        for (int d=0; d<4; d++) {
                            int x = a + dx[d];
                            int y = b + dy[d];
                            if (x < 0 || x >= n || y < 0 || y >= m) continue;
                            if (chk[x][y] || v[x][y] <= 0) continue;
                            chk[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        if (cnt >= 2) {
            cout << t << '\n';
            return 0;
        }
        else if (cnt == 0) {
            cout << 0 << '\n';
            return 0;
        }
        vector<vector<int>> update(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int cnt = 0;
                for (int d=0; d<4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (v[x][y] == 0) cnt++;
                }
                update[i][j] = cnt;
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                v[i][j] -= update[i][j];
                if (v[i][j] < 0) v[i][j] = 0;
            }
        }
        t++;
    }
}