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

vector<int> adj[10101];
int c[10101], d[10101];

bool dfs(int x) {
    for (int y : adj[x]) {
        if (c[y]) continue;
        c[y] = true;
        if (d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

int mp[110][110];
int mark[110][110][2];
int n;
void solve() {
    cin >> n;
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        mp[a][b] = -1;
    }
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        cnt++;
        int x = i;
        int y = 1;
        int tt = i;
        while (tt--) {
            if (mp[x][y]) {
                cnt++;
                x--;
                y++;
                continue;
            }
            mark[x][y][0] = cnt;
            x--;
            y++;
        }
    }
    for (int j=2; j<=n; j++) {
        cnt++;
        int x = n;
        int y = j;
        int tt = n-j+1;
        while (tt--) {
            if (mp[x][y]) {
                cnt++;
                x--;
                y++;
                continue;
            }
            mark[x][y][0] = cnt;
            x--;
            y++;
        }
    }

    cnt = 0;
    for (int i=1; i<=n; i++) {
        cnt++;
        int x = i;
        int y = 1;
        int tt = n-i+1;
        while (tt--) {
            if (mp[x][y]) {
                cnt++;
                x++;
                y++;
                continue;
            }
            mark[x][y][1] = cnt;
            x++;
            y++;
        }
    }
    for (int j=2; j<=n; j++) {
        cnt++;
        int x = 1;
        int y = j;
        int tt = n-j+1;
        while (tt--) {
            if (mp[x][y]) {
                cnt++;
                x++;
                y++;
                continue;
            }
            mark[x][y][1] = cnt;
            x++;
            y++;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (mp[i][j]) continue;
            if (mark[i][j][0] == 0 || mark[i][j][1] == 0) {
                int a = 3;
                a = 3 + 3;
            }
            adj[mark[i][j][0]].push_back(mark[i][j][1]);
        }
    }
    int ans = 0;
    for (int i=1; i<=10000; i++) {
        memset(c, 0, sizeof c);
        if (dfs(i)) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}