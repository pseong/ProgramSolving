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

int n, m, c[1010101];
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    int idx = 1;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (v[i][j] == 1) {
                idx++;
                queue<pi> q;
                q.push({i, j});
                v[i][j] = idx;
                int cnt = 0;
                while (q.size()) {
                    cnt++;
                    auto [x, y] = q.front();
                    q.pop();
                    for (int d=0; d<4; d++) {
                        int a = x + dx[d];
                        int b = y + dy[d];
                        if (a < 1 || a > n || b < 1 || b > m) continue;
                        if (v[a][b] != 1) continue;
                        v[a][b] = idx;
                        q.push({a, b});
                    }
                }
                c[idx] = cnt;
                ans = max(ans, cnt);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (v[i][j]) continue;
            set<int> st;
            for (int d=0; d<4; d++) {
                int a = i + dx[d];
                int b = j + dy[d];
                if (a < 1 || a > n || b < 1 || b > m) continue;
                st.insert(v[a][b]);
            }
            int cnt = 1;
            for (int x : st) {
                cnt += c[x];
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
}