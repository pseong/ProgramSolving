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

int v[110][110];
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    int t = 0;
    while (true) {
        vector<int> cnt(2);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (v[i][j] == 2) v[i][j] = 0, cnt[0]++;
                else if (v[i][j] == 1) cnt[1]++;
            }
        }
        if (cnt[1] == 0) {
            cout << t << '\n' << cnt[0] << '\n';
            break;
        }
        vector<vector<int>> chk(n + 1, vector<int>(m + 1));
        queue<pi> q;
        q.push({1, 1});
        chk[1][1] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d=0; d<4; d++) {
                int a = x + dx[d];
                int b = y + dy[d];
                if (a < 1 || a > n || b < 1 || b > m) continue;
                if (v[a][b]) {
                    v[a][b] = 2;
                    continue;
                }
                if (chk[a][b]) continue;
                chk[a][b] = 1;
                q.push({a, b});
            }
        }
        t++;
    }
}