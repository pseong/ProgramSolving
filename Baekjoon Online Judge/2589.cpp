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

int n, m;
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            if (s[j] == 'L') v[i][j] = 1;
        }
    }
    int ans = 0;
    vector<vector<int>> chk(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 1) {
                vector<vector<int>> chk(n, vector<int>(m));
                vector<vector<int>> dist(n, vector<int>(m));
                queue<pi> q;
                q.push({i, j});
                chk[i][j] = 1;
                vector<int> ret(3);
                while (q.size()) {
                    auto [x, y] = q.front();
                    q.pop();
                    ans = max(ans, dist[x][y]);
                    for (int d=0; d<4; d++) {
                        int a = x + dx[d];
                        int b = y + dy[d];
                        if (a < 0 || a >= n || b < 0 || b >= m) continue;
                        if (v[a][b] == 0 || chk[a][b] == 1) continue;
                        chk[a][b] = 1;
                        dist[a][b] = dist[x][y] + 1;
                        q.push({a, b});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}