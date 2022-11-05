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

vector<vector<int>> v;
int n, m, g, r;
vector<pi> can;

int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};

int cntG, cntR, ans;

void go(int idx) {
    if (idx == (int)can.size()) {
        if (cntG != g || cntR != r) return;
        vector<vector<int>> mp(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                mp[i][j] = v[i][j];
            }
        }
        queue<pi> G, R;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mp[i][j] == 3) G.push({i, j});
                if (mp[i][j] == 4) R.push({i, j});
            }
        }
        while (G.size() && R.size()) {
            int t = G.size();
            while (t--) {
                int a, b;
                tie(a, b) = G.front();
                G.pop();
                if (mp[a][b] == 10) continue;
                if (mp[a][b] == 5) mp[a][b] = 3;
                for (int d=0; d<4; d++) {
                    int x = a + dx[d];
                    int y = b + dy[d];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (mp[x][y] == 1 || mp[x][y] == 2) {
                        mp[x][y] = 5;
                        G.push({x, y});
                    }
                }
            }
            t = R.size();
            while (t--) {
                int a, b;
                tie(a, b) = R.front();
                R.pop();
                for (int d=0; d<4; d++) {
                    int x = a + dx[d];
                    int y = b + dy[d];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (mp[x][y] == 1 || mp[x][y] == 2) {
                        mp[x][y] = 4;
                        R.push({x, y});
                    }
                    else if (mp[x][y] == 5) {
                        mp[x][y] = 10;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mp[i][j] == 10) cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }
    go(idx + 1);
    if (cntG < g) {
        v[can[idx].first][can[idx].second] = 3;
        cntG++;
        go(idx + 1);
        v[can[idx].first][can[idx].second] = 2;
        cntG--;
    }
    if (cntR < r) {
        v[can[idx].first][can[idx].second] = 4;
        cntR++;
        go(idx + 1);
        v[can[idx].first][can[idx].second] = 2;
        cntR--;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> g >> r;
    v.assign(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                can.push_back({i, j});
            }
        }
    }
    go(0);
    cout << ans << '\n';
}