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

    int r, c;
    cin >> r >> c;
    vector<string> v(r);
    for (int i=0; i<r; i++) {
        cin >> v[i];
    }
    queue<pi> J, F;
    vector<vector<int>> chkJ(r, vector<int>(c, 0));
    vector<vector<int>> chkF(r, vector<int>(c, 0));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (v[i][j] == 'J') {
                J.push({i, j});
                chkJ[i][j] = 1;
            }
            if (v[i][j] == 'F') {
                F.push({i, j});
                chkF[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while (true) {
        cnt++;
        if (J.empty()) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int i=0; i<r; i++) {
            if (v[i][0] == 'J' || v[i][c-1] == 'J') {
                cout << cnt << '\n';
                return 0;
            }
        }
        for (int i=0; i<c; i++) {
            if (v[0][i] == 'J' || v[r-1][i] == 'J') {
                cout << cnt << '\n';
                return 0;
            }
        }
        int sz = J.size();
        while (sz--) {
            auto [i, j] = J.front();
            J.pop();
            if (v[i][j] == 'F') continue;
            for (int d=0; d<4; d++) {
                int x = i+dx[d];
                int y = j+dy[d];
                if (x < 0 || x >= r || y < 0 || y >= c) continue;
                if (v[x][y] != '.' || chkJ[x][y]) continue;
                chkJ[x][y] = 1;
                v[x][y] = 'J';
                J.push({x, y});
            }
        }
        sz = F.size();
        while (sz--) {
            auto [i, j] = F.front();
            F.pop();
            for (int d=0; d<4; d++) {
                int x = i+dx[d];
                int y = j+dy[d];
                if (x < 0 || x >= r || y < 0 || y >= c) continue;
                if (v[x][y] == '#' || chkF[x][y]) continue;
                chkF[x][y] = 1;
                v[x][y] = 'F';
                F.push({x, y});
            }
        }
    }
}