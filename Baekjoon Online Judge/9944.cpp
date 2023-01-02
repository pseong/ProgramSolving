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

vector<string> s, ans;
int n, m, cnt, res;
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

void go(int x, int y, int cnt) {
    bool ok = true;
    for (int d=0; d<4; d++) {
        int a = x + dx[d];
        int b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (s[a][b] == '*') continue;
        ok = false;
        vector<pi> hist;
        while (true) {
            hist.push_back({a, b});
            s[a][b] = '*';
            int na = a + dx[d];
            int nb = b + dy[d];
            if (na < 0 || na >= n || nb < 0 || nb >= m) break;
            if (s[na][nb] == '*') break;
            a = na;
            b = nb;
        }
        go(a, b, cnt + 1);
        for (auto [x, y] : hist) {
            s[x][y] = '.';
        }
    }
    if (ok) if (s == ans) res = min(res, cnt);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int CASE = 0;
    while (cin >> n >> m) {
        CASE++;
        ans.assign(n, string(m, '*'));
        s.resize(n);
        res = 1e9;
        for (int i=0; i<n; i++) {
            cin >> s[i];
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (s[i][j] == '.') {
                    s[i][j] = '*';
                    go(i, j, 0);
                    s[i][j] = '.';
                }
            }
        }
        cout << "Case " << CASE << ": ";
        if (res == 1e9) cout << -1 << '\n';
        else cout << res << '\n';
    }
}