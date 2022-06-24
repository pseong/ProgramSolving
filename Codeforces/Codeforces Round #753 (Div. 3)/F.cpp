#include <bits/stdc++.h>
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

int n, m;
string s[2020];
int dp[2020][2020], depth[2020][2020], chk[2020][2020];

map<char, int> mp;
int dx[] { -1, 0, 0, 1 };
int dy[] { 0, -1, 1, 0 };

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            dp[i][j] = 0;
            depth[i][j] = 0;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (dp[i][j]) continue;
            stack<pi> stk;
            int x = i;
            int y = j;
            int d = 0;
            while (true) {
                if (dp[x][y] || x < 0 || x >= n || y < 0 || y >= m) {
                    int cnt = 1;
                    if (!(x < 0 || x >= n || y < 0 || y >= m)) cnt = dp[x][y] + 1;
                    while (stk.size()) {
                        auto [a, b] = stk.top();
                        chk[a][b] = 0;
                        stk.pop();
                        dp[a][b] = cnt;
                        cnt++;
                    }
                    break;
                }
                if (chk[x][y]) {
                    int cnt = d - depth[x][y];
                    bool out = false;
                    while (stk.size()) {
                        auto [a, b] = stk.top();
                        chk[a][b] = 0;
                        stk.pop();
                        if (out) cnt++;
                        dp[a][b] = cnt;
                        if (a == x && b == y) out = true;
                    }
                    break;
                }
                chk[x][y] = 1;
                stk.push({x, y});
                depth[x][y] = d;
                int a = x+dx[mp[s[x][y]]];
                int b = y+dy[mp[s[x][y]]];
                x = a;
                y = b;
                d++;
            }
        }
    }

    int mx = 0;
    int a = 0;
    int b = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mx < dp[i][j]) {
                mx = dp[i][j];
                a = i;
                b = j;
            }
        }
    }
    cout << a+1 << ' ' << b+1 << ' ' << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    mp['U'] = 0;
    mp['L'] = 1;
    mp['R'] = 2;
    mp['D'] = 3;

    int T; cin >> T;
    while (T--) {
        solve();
    }
}