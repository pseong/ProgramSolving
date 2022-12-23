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
    
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<vector<int>> chk(n + 1, vector<int>(n + 1, 1e9));
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=n; j++) {
            v[i][j] = s[j-1] - '0';
        }
    }
    chk[1][1] = 0;
    queue<pi> q;
    q.push({1, 1});
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        int dx[] {-1, 1, 0, 0};
        int dy[] {0, 0, -1, 1};
        for (int d=0; d<4; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            if (a < 1 || a > n || b < 1 || b > n) continue;
            if (chk[a][b] <= chk[x][y] + (v[a][b] == 0 ? 1 : 0)) continue;
            chk[a][b] = chk[x][y] + (v[a][b] == 0 ? 1 : 0);
            q.push({a, b});
        }
    }
    cout << chk[n][n] << '\n';
}