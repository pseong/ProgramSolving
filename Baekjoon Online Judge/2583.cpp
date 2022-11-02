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

int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m, 0));
    while (k--) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int i=x1; i<=x2-1; i++) {
            for (int j=y1; j<=y2-1; j++) {
                v[i][j] = 1;
            }
        }
    }
    vector<int> ans;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 0) {
                queue<pi> q;
                q.push({i, j});
                v[i][j] = 1;
                int cnt = 0;
                while (q.size()) {
                    cnt++;
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for (int d=0; d<4; d++) {
                        int a = x + dx[d];
                        int b = y + dy[d];
                        if (a < 0 || a >= n || b < 0 || b >=m) continue;
                        if (v[a][b]) continue;
                        v[a][b] = 1;
                        q.push({a, b});
                    }
                }
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}