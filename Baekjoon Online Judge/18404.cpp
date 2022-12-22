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
    int x, y;
    cin >> x >> y;
    vector<vector<int>> chk(n + 1, vector<int>(n + 1, -1));
    chk[x][y] = 0;
    queue<pi> q;
    q.push({x, y});
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        int dx[] {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] {-1, 1, -2, 2, -2, 2, -1, 1};
        for (int d=0; d<8; d++) {
            int a = x + dx[d];
            int b = y + dy[d];
            if (a < 1 || a > n || b < 1 || b > n) continue;
            if (chk[a][b] != -1) continue;
            chk[a][b] = chk[x][y] + 1;
            q.push({a, b});
        }
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << chk[a][b] << ' ';
    }
    cout << '\n';
}