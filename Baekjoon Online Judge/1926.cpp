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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> dx{-1, 0, 0, 1};
    vector<int> dy{0, -1, 1, 0};
    vector<int> ans(2);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 1) {
                ans[0]++;
                queue<pi> q;
                q.push({i, j});
                int cnt = 1;
                while (q.size()) {
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();
                    v[a][b] = 0;
                    for (int d=0; d<4; d++) {
                        int x = a+dx[d];
                        int y = b+dy[d];
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        if (v[x][y] == 0) continue;
                        v[x][y] = 0;
                        cnt++;
                        q.push({x, y});
                    }
                }
                if (ans[1] < cnt) ans[1] = cnt;
            }
        }
    }
    cout << ans[0] << '\n' << ans[1] << '\n';
}