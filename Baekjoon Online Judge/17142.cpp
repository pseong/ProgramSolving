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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<pi> s;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) s.push_back({i, j});
        }
    }
    
    vector<int> c(s.size());
    for (int i=0; i<k; i++) c[i] = 1;
    sort(c.begin(), c.end());
    int ans = 1e9;
    do {
        queue<pi> q;
        vector<vector<int>> chk(n + 1, vector<int>(n + 1, 1e9));
        for (int i=0; i<(int)c.size(); i++) {
            if (c[i] == 0) continue;
            q.push(s[i]);
            chk[s[i].first][s[i].second] = 0;
        }
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            int dx[] {-1, 1, 0, 0};
            int dy[] {0, 0, -1, 1};
            for (int d=0; d<4; d++) {
                int a = x + dx[d];
                int b = y + dy[d];
                if (a < 1 || a > n || b < 1 || b > n) continue;
                if (chk[a][b] != 1e9 || v[a][b] == 1) continue;
                chk[a][b] = chk[x][y] + 1;
                q.push({a, b});
            }
        }
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (v[i][j] == 0) cnt = max(cnt, chk[i][j]);
            }
        }
        ans = min(ans, cnt);
    } while (next_permutation(c.begin(), c.end()));
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}