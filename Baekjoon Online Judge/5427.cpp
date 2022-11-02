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

void test() {
    int r, c;
    cin >> c >> r;
    vector<string> v(r);
    for (int i=0; i<r; i++) {
        cin >> v[i];
    }
    queue<pi> J, F;
    vector<vector<int>> chkJ(r, vector<int>(c, 0));
    vector<vector<int>> chkF(r, vector<int>(c, 0));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (v[i][j] == '@') {
                J.push({i, j});
                chkJ[i][j] = 1;
            }
            if (v[i][j] == '*') {
                F.push({i, j});
                chkF[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while (J.size()) {
        cnt++;
        int sz = F.size();
        while (sz--) {
            auto [i, j] = F.front();
            F.pop();
            for (int d=0; d<4; d++) {
                int x = i+dx[d];
                int y = j+dy[d];
                if (x < 0 || x >= r || y < 0 || y >= c) continue;
                if (v[x][y] == '#' || chkF[x][y]) continue;
                chkF[x][y] = 1;
                if (v[x][y] == '@') continue;
                v[x][y] = '*';
                F.push({x, y});
            }
        }
        sz = J.size();
        while (sz--) {
            auto [i, j] = J.front();
            if (i == 0 || i == r-1 || j == 0 || j == c-1) {
                cout << cnt << '\n';
                return;
            }
            J.pop();
            for (int d=0; d<4; d++) {
                int x = i+dx[d];
                int y = j+dy[d];
                if (x < 0 || x >= r || y < 0 || y >= c) continue;
                if (v[x][y] != '.' || chkJ[x][y]) continue;
                if (v[x][y] == '*') continue;
                chkJ[x][y] = 1;
                v[x][y] = '@';
                J.push({x, y});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        test();
    }
}