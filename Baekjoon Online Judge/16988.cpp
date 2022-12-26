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

int n, m, ans;
int v[30][30];
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

void cal() {
    vector<vector<int>> chk(n + 1, vector<int>(m + 1));
    int sum = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (v[i][j] == 2 && chk[i][j] == 0) {
                queue<pi> q;
                q.push({i, j});
                bool ok = true;
                chk[i][j] = 1;
                int cnt = 0;
                while (q.size()) {
                    cnt++;
                    auto [x, y] = q.front();
                    q.pop();
                    for (int d=0; d<4; d++) {
                        int a = x + dx[d];
                        int b = y + dy[d];
                        if (a < 1 || a > n || b < 1 || b > m) continue;
                        if (chk[a][b]) continue;
                        if (v[a][b] == 0) ok = false;
                        if (v[a][b] != 2) continue;
                        chk[a][b] = 1;
                        q.push({a, b});
                    }
                }
                if (ok) sum += cnt;
            }
        }
    }
    ans = max(ans, sum);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<pi> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 0) q.push_back({i, j});
        }
    }
    vector<bool> chk(q.size());
    chk[0] = 1;
    chk[1] = 1;
    sort(chk.begin(), chk.end());
    do {
        for (int i=0; i<(int)q.size(); i++) {
            if (chk[i]) {
                v[q[i].first][q[i].second] = 1;
            }
        }
        cal();
        for (int i=0; i<(int)q.size(); i++) {
            if (chk[i]) {
                v[q[i].first][q[i].second] = 0;
            }
        }
    } while (next_permutation(chk.begin(), chk.end()));
    cout << ans << '\n';
}