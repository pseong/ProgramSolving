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
    
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> V(n + 2, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> V[i][j];
        }
    }
    int ans = 0;
    vector<int> o(4);
    for (o[1]=1; o[1]<=m; o[1]++) {
        for (o[2]=o[1]+1; o[2]<=m; o[2]++) {
            for (o[3]=o[2]+1; o[3]<=m; o[3]++) {
                int res = 0;
                auto v = V;
                for (int k=0; k<=n; k++) {
                    set<pair<int, int>> f;
                    for (int p=1; p<=3; p++) {
                        vector<vector<int>> chk(n + 2, vector<int>(m + 1));
                        queue<pi> q;
                        q.push({n + 1, o[p]});
                        chk[n+1][o[p]] = 1;
                        for (int c=0; c<=d; c++) {
                            int sz = q.size();
                            while (sz--) {
                                auto [x, y] = q.front();
                                q.pop();
                                if (v[x][y]) {
                                    f.insert({x, y});
                                    goto g;
                                }
                                int dx[] {0, -1, 0};
                                int dy[] {-1, 0, 1};
                                for (int r=0; r<3; r++) {
                                    int a = x + dx[r];
                                    int b = y + dy[r];
                                    if (a < 1 || a > n || b < 1 || b > m) continue;
                                    if (chk[a][b]) continue;
                                    chk[a][b] = 1;
                                    q.push({a, b});
                                }
                            }
                        }
                        g:
                        continue;
                    }
                    res += f.size();
                    for (auto [x, y] : f) {
                        v[x][y] = 0;
                    }
                    for (int i=n; i>=1; i--) {
                        for (int j=1; j<=m; j++) {
                            v[i][j] = v[i-1][j];
                        }
                    }
                }
                ans = max(ans, res);
            }
        }
    }
    cout << ans << '\n';
}