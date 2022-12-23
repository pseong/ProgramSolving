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
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    queue<pi> q;
    vector<vector<int>> chk(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == '2') {
                q.push({i, j});
                chk[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while (q.size()) {
        cnt++;
        int t = q.size();
        while (t--) {
            auto [x, y] = q.front();
            q.pop();
            int dx[] {-1, 1, 0, 0};
            int dy[] {0, 0, -1, 1};
            for (int d=0; d<4; d++) {
                int a = x + dx[d];
                int b = y + dy[d];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (chk[a][b] || v[a][b] == '1') continue;
                else if (v[a][b] != '0') {
                     cout << "TAK\n" << cnt << '\n';
                    return 0;
                }
                chk[a][b] = 1;
                q.push({a, b});
            }
        }
    }
    cout << "NIE\n";
}