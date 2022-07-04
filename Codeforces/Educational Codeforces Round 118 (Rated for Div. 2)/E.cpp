#include <bits/stdc++.h>
#define int long long
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

string s[1010101], ans[1010101];
int n, m;
int dx[]{-1, 0, 0, 1};
int dy[]{0, -1, 1, 0};

void _solve(int x, int y) {
    vector<vector<int>> chk(n, vector<int>(m, 0));
    queue<pi> q;
    q.push({x, y});
    chk[x][y] = 1;
    while (q.size()) {
        auto [a, b] = q.front();
        q.pop();
        for (int d=0; d<4; d++) {
            int i=a+dx[d];
            int j=b+dy[d];
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (chk[i][j] || s[i][j] == '#') continue;
            int cnt = 0;
            for (int f=0; f<4; f++) {
                int u=i+dx[f];
                int v=j+dy[f];
                if (u < 0 || u >= n || v < 0 || v >= m) continue;
                if (s[u][v] == '.' && ans[u][v] != '+') cnt++;
            }
            if (cnt <= 1) {
                ans[i][j] = '+';
                chk[i][j] = 1;
                q.push({i, j});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        ans[i] = s[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == 'L') {
                _solve(i, j);
                goto g;
            }
        }
    }
    g:
    for (int i=0; i<n; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}