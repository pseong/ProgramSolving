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

int chk[110][110][4];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    queue<ti> q;
    memset(chk, -1, sizeof chk);
    int r, c;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 'C') {
                if (q.empty()) {
                    for (int k=0; k<4; k++) {
                        q.push({i, j, k});
                        chk[i][j][k] = 0;
                    }
                }
                else {
                    r = i;
                    c = j;
                }
            }
        }
    }
    while (q.size()) {
        auto [x, y, g] = q.front();
        q.pop();
        int dx[] {-1, 0, 1, 0};
        int dy[] {0, 1, 0, -1};
        for (int d=g-1; d<=g+1; d++) {
            int k = (d + 4) % 4;
            int a = x + dx[k];
            int b = y + dy[k];
            int cost = (k == g ? 0 : 1);
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (v[a][b] == '*') continue;
            if (chk[a][b][k] != -1 && chk[a][b][k] <= chk[x][y][g] + cost) continue;
            chk[a][b][k] = chk[x][y][g] + cost;
            q.push({a, b, k});
        }
    }
    int ans = 1e9;
    for (int i=0; i<4; i++) {
        if (chk[r][c][i] != -1) ans = min(ans, chk[r][c][i]);
    }
    cout << ans << '\n';
}