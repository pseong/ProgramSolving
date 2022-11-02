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

    int n, m, p;
    cin >> n >> m >> p;
    vector<int> sp(p+1);
    for (int i=1; i<=p; i++) {
        cin >> sp[i];
    }
    vector<string> v(m);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    queue<pi> q[10];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] >= '1' && v[i][j] <= '9') q[v[i][j]-'0'].push({i, j});
        }
    }
    while (true) {
        bool ok = false;
        for (int i=1; i<=p; i++) {
            if (q[i].size()) ok = true;
        }
        if (!ok) {
            vector<int> ans(p+1);
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (v[i][j] >= '1' && v[i][j] <= '9') ans[v[i][j]-'0']++;
                }
            }
            for (int i=1; i<=p; i++) {
                cout << ans[i] << ' ';
            }
            return 0;
        }
        for (int i=1; i<=p; i++) {
            for (int k=0; k<sp[i]; k++) {
                int cnt = q[i].size();
                if (cnt == 0) break;
                while (cnt--) {
                    int a, b;
                    tie(a, b) = q[i].front();
                    q[i].pop();
                    for (int d=0; d<4; d++) {
                        int x = a + dx[d];
                        int y = b + dy[d];
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        if (v[x][y] != '.') continue;
                        v[x][y] = i + '0';
                        q[i].push({x, y});
                    }
                }
            }
        }
    }
}