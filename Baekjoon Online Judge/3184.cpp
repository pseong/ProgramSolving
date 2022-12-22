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

string v[300];
int chk[300][300], cnt[90000][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int idx = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (chk[i][j] == 0 && v[i][j] != '#') {
                idx++;
                queue<pi> q;
                q.push({i, j});
                chk[i][j] = idx;
                while (q.size()) {
                    auto [x, y] = q.front();
                    q.pop();
                    int dx[] {-1, 1, 0, 0};
                    int dy[] {0, 0, -1, 1};
                    for (int d=0; d<4; d++) {
                        int a = x + dx[d];
                        int b = y + dy[d];
                        if (a < 0 || a >= n || b < 0 || b >= m) continue;
                        if (v[a][b] == '#') continue;
                        if (chk[a][b]) continue;
                        chk[a][b] = idx;
                        q.push({a, b});
                    }
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 'v') cnt[chk[i][j]][0]++;
            else if (v[i][j] == 'o') cnt[chk[i][j]][1]++;
        }
    }
    vector<int> ans(2);
    for (int i=1; i<=idx; i++) {
        if (cnt[i][0] < cnt[i][1]) ans[1] += cnt[i][1];
        else ans[0] += cnt[i][0];
    }
    cout << ans[1] << ' ' << ans[0] << '\n';
}