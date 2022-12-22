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

int v[110][110], chk[110][110];
int dx[2][6] = {{-1, -1, 0, 0, 1, 1}, {-1, -1, 0, 0, 1, 1}};
int dy[2][6] = {{-1, 0, -1, 1, -1, 0}, {0, 1, -1, 1, 0, 1}};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    queue<pi> q;
    q.push({0, 0});
    chk[0][0] = 1;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d=0; d<6; d++) {
            int a = x + dx[x%2][d];
            int b = y + dy[x%2][d];
            if (a < 0 || a > n + 1 || b < 0 || b > m + 1) continue;
            if (chk[a][b] || v[a][b]) continue;
            chk[a][b] = 1;
            q.push({a, b});
        }
    }
    int ans = 0;
    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=m+1; j++) {
            if (chk[i][j] == 0) continue;
            for (int d=0; d<6; d++) {
                int a = i + dx[i%2][d];
                int b = j + dy[i%2][d];
                if (a < 0 || a > n || b < 0 || b > m) continue;
                if (v[a][b]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}