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
    vector<vector<int>> v(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 1;
    for (int z=1; z<=100; z++) {
        vector<vector<int>> chk(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (v[i][j] <= z) chk[i][j] = 1;
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (chk[i][j] == 0) {
                    cnt++;
                    chk[i][j] = 1;
                    queue<pi> q;
                    q.push({i, j});
                    while (q.size()) {
                        int a, b;
                        tie(a, b) = q.front();
                        q.pop();
                        int dx[] {-1, 0, 0, 1};
                        int dy[] {0, -1, 1, 0};
                        for (int d=0; d<4; d++) {
                            int x = a + dx[d];
                            int y = b + dy[d];
                            if (x < 0 || x >= n || y < 0 || y >= n) continue;
                            if (chk[x][y]) continue;
                            chk[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}