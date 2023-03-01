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

int v[555][555], chk[555][555], ans, now;
int n, m;
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

void dfs(int x, int y, int cnt) {
    chk[x][y] = 1;
    now += v[x][y];
    if (cnt == 4) ans = max(ans, now);
    else {
        for (int d=0; d<4; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (chk[a][b]) continue;
            dfs(a, b, cnt+1);
        }
    }
    chk[x][y] = 0;
    now -= v[x][y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dfs(i, j, 1);
            int a = v[i][j] + v[i-1][j] + v[i+1][j] + v[i][j-1] + v[i][j+1];
            ans = max({ans, a-v[i-1][j], a-v[i+1][j], a-v[i][j-1], a-v[i][j+1]});
        }
    }
    cout << ans << '\n';
}