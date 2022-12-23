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

int chk[60][60][2600];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=n; j++) {
            v[i][j] = s[j-1] - '0';
        }
    }
    chk[1][1][0] = 1;
    queue<ti> q;
    q.push({1, 1, 0});
    while (q.size()) {
        auto [x, y, c] = q.front();
        q.pop();
        int dx[] {-1, 1, 0, 0};
        int dy[] {0, 0, -1, 1};
        for (int d=0; d<4; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            if (a < 1 || a > n || b < 1 || b > n) continue;
            int w = ((v[a][b] == 0) ? c + 1 : c);
            if (chk[a][b][w] || w >= n * n) continue;
            chk[a][b][w] = 1;
            if (a == 8 && b == 8) {
                int f = 3;
                f += f;
            }
            q.push({a, b, w});
        }
    }
    for (int i=0; i<2600; i++) {
        if (chk[n][n][i]) {
            cout << i << '\n';
            return 0;
        }
    }
}