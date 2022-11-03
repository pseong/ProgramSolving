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

int dx[] {1, 0};
int dy[] {0, 1};
string v[5];
int chk[50][50], cntS, cntY, ans;

void go(int x, int y) {
    if (cntY >= 4) {
        return;
    }
    if (cntS + cntY == 7) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (chk[i][j]) {
                    queue<pi> q;
                    q.push({i, j});
                    vector<vector<int>> visit(5, vector<int>(5, 0));
                    visit[i][j] = 1;
                    int cnt = 0;
                    while (q.size()) {
                        cnt++;
                        int a, b;
                        tie(a, b) = q.front();
                        q.pop();
                        int dx[] {-1, 0, 0, 1};
                        int dy[] {0, -1, 1, 0};
                        for (int d=0; d<4; d++) {
                            int x = a + dx[d];
                            int y = b + dy[d];
                            if (x < 0 || x >= 5 || y < 0 || y >= 5) continue;
                            if (visit[x][y] || !chk[x][y]) continue;
                            visit[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                    if (cnt == 7) ans++;
                    return;
                }
            }
        }
    }
    if (y >= 5) {
        x++;
        y = 0;
        if (x >= 5) return;
    }
    go(x, y + 1);
    chk[x][y] = 1;
    if (v[x][y] == 'Y') cntY++;
    else if (v[x][y] == 'S') cntS++;
    go(x, y + 1);
    chk[x][y] = 0;
    if (v[x][y] == 'Y') cntY--;
    else if (v[x][y] == 'S') cntS--;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0; i<5; i++) {
        cin >> v[i];
    }
    go(0, 0);
    cout << ans << '\n';
}