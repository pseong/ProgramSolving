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

int dx[] {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
vector<string> v;

int count(int x, int y) {
    int cnt = 0;
    for (int d=0; d<8; d++) {
        int a = x + dx[d];
        int b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (v[a][b] == '.') cnt++;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> chk(n, vector<int>(m));
    vector<pi> q;
    for (int i=1; i<n-1; i++) {
        for (int j=1; j<m-1; j++) {
            if (v[i][j] != '.' && count(i, j) >= v[i][j] - '0') {
                chk[i][j] = 1;
                q.push_back({i, j});
            }
        }
    }
    int ans = 0;
    while (q.size()) {
        ans++;
        for (int i=0; i<(int)q.size(); i++) {
            v[q[i].first][q[i].second] = '.';
        }
        vector<pi> tmp;
        for (int i=0; i<(int)q.size(); i++) {
            auto [x, y] = q[i];
            for (int d=0; d<8; d++) {
                int a = x + dx[d];
                int b = y + dy[d];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (chk[a][b] || v[a][b] == '.' || count(a, b) < v[a][b] - '0') continue;
                chk[a][b] = 1;
                tmp.push_back({a, b});
            }
        }
        q = tmp;
    }
    cout << ans << '\n';
}