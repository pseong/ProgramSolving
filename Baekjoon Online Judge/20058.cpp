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

int v[100][100], tmp[100][100];

void rotate(int x, int y, int n, int len) {
    if (n != len) {
        rotate(x, y, n/2, len);
        rotate(x, y+n/2, n/2, len);
        rotate(x+n/2, y, n/2, len);
        rotate(x+n/2, y+n/2, n/2, len);
        return;
    }
    for (int i=0; i<n/2; i++) {
        for (int j=i; j<n-1-i; j++) {
            int tmp = v[x+i][y+j];
            v[x+i][y+j] = v[x+n-1-j][y+i];
            v[x+n-1-j][y+i] = v[x+n-1-i][y+n-1-j];
            v[x+n-1-i][y+n-1-j] = v[x+j][y+n-1-i];
            v[x+j][y+n-1-i] = tmp;
        }
    }
}

int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};

void solve(int CASE) {
    int n, q;
    cin >> n >> q;
    n = 1 << n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    while (q--) {
        int l;
        cin >> l;
        rotate(1, 1, n, 1<<l);
        memset(tmp, 0, sizeof tmp);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                int cnt = 0;
                for (int d=0; d<4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (x < 1 || x > n || y < 1 || y > n) continue;
                    if (v[x][y]) cnt++;
                }
                if (cnt < 3) tmp[i][j] = -1;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                v[i][j] += tmp[i][j];
                v[i][j] = max(0, v[i][j]);
            }
        }
    }

    vector<int> ans(2);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!v[i][j]) continue;
            vector<int> res(2);
            res[1]++;
            res[0] = v[i][j];
            v[i][j] = 0;
            queue<pi> q;
            q.push({i, j});
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d=0; d<4; d++) {
                    int a = x + dx[d];
                    int b = y + dy[d];
                    if (a < 1 || a > n || b < 1 || b > n) continue;
                    if (!v[a][b]) continue;
                    res[0] += v[a][b];
                    v[a][b] = 0;
                    q.push({a, b});
                    res[1]++;
                }
            }
            ans[0] += res[0];
            ans[1] = max(ans[1], res[1]);
        }
    }
    cout << ans[0] << '\n' << ans[1] << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}