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

int v[1010][1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            v[i][j] = s[j] - '0';
        }
    }
    bool ok = false;
    for (int j=0; j<m; j++) {
        if (v[0][j] == 0) {
            queue<pi> q;
            q.push({0, j});
            v[0][j] = 1;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n-1) ok = true;
                int dx[] {-1, 1, 0, 0};
                int dy[] {0, 0, -1, 1};
                for (int d=0; d<4; d++) {
                    int a = x + dx[d];
                    int b = y + dy[d];
                    if (a < 0 || a >= n || b < 0 || b >= m) continue;
                    if (v[a][b] == 1) continue;
                    v[a][b] = 1;
                    q.push({a, b});
                }
            }
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}