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
    vector<vector<int>> chk(r, vector<int>(c));
    for (int i=0; i<r; i++) {
        cin >> v[i];
    }
    queue<pi> L[3], X;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (v[i][j] == 'L') {
                if (L[1].empty()) {
                    v[i][j] = '1';
                    L[1].push({i, j});
                }
                else {
                    v[i][j] = '2';
                    L[2].push({i, j});
                }
            }
            else if (v[i][j] == 'X') {
                bool ok = false;
                for (int d=0; d<4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (x < 0 || x >= r || y < 0 || y >= c) continue;
                    if (v[x][y] == '.' || v[x][y] == 'L') ok = true;
                }
                if (ok) {
                    chk[i][j] = 1;
                    X.push({i, j});
                }
            }
        }
    }
    int day = 0;
    while (true) {
        for (int f=1; f<=2; f++) {
            while (L[f].size()) {
                int a, b;
                tie(a, b) = L[f].front();
                L[f].pop();
                for (int d=0; d<4; d++) {
                    int x = a + dx[d];
                    int y = b + dy[d];
                    if (x < 0 || x >= r || y < 0 || y >= c) continue;
                    if (v[x][y] == '.') {
                        v[x][y] = '0' + f;
                        L[f].push({x, y});
                    }
                    else if (v[x][y] == '3' - f) {
                        cout << day << '\n';
                        return 0;
                    }
                }
            }
        }
        int t = X.size();
        while (t--) {
            int a, b;
            tie(a, b) = X.front();
            X.pop();
            v[a][b] = '.';
            for (int d=0; d<4; d++) {
                int x = a + dx[d];
                int y = b + dy[d];
                if (x < 0 || x >= r || y < 0 || y >= c) continue;
                if (v[x][y] == 'X' && chk[x][y] == 0) {
                    chk[x][y] = 1;
                    X.push({x, y});
                }
                for (int f=1; f<=2; f++) {
                    if (v[x][y] == '0' + f) {
                        L[f].push({x, y});
                        v[x][y] = '0' + f;
                    }
                }
            }
        }
        day++;
    }
}