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

int v[10][10];
int dx[] {-1, 0, 1, 0};
int dy[] {0, 1, 0, -1};
vector<vector<int>> pos({{0}, {0, 2}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}});

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> tv;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
            if (v[i][j] >= 1 && v[i][j] <= 5) {
                tv.push_back({v[i][j]-1, i, j});
            }
            if (v[i][j] == 0) cnt++;
        }
    }
    int k = tv.size();
    vector<int> p(k);
    int ans = 1e9;
    for (ll i=0; i<(1LL<<(k*2)); i++) {
        for (int j=0; j<k; j++) {
            bool o = (i & 1LL<<(j*2));
            bool x = (i & 1LL<<(j*2+1));
            p[j] = x*2 + o;
        }
        int cc = 0;
        for (int a=0; a<k; a++) {
            auto [num, x, y] = tv[a];
            vector<int> f = pos[num];
            for (int i=0; i<(int)f.size(); i++) {
                f[i] += p[a];
                f[i] %= 4;
            }
            for (int i=0; i<(int)f.size(); i++) {
                int d = f[i];
                int r = x;
                int c = y;
                while (true) {
                    int nr = r + dx[d];
                    int nc = c + dy[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) break;
                    if (v[nr][nc] == 6) break;
                    if (v[nr][nc] == 0) {
                        v[nr][nc] = 7;
                        cc++;
                    }
                    r = nr;
                    c = nc;
                }
            }
        }
        ans = min(ans, cnt - cc);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] == 7) v[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
}