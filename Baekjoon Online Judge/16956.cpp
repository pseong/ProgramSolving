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

string v[550];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == '.') v[i][j] = 'D';
            if (v[i][j] == 'W') {
                int dx[] {-1, 1, 0, 0};
                int dy[] {0, 0, -1, 1};
                for (int d=0; d<4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (v[x][y] == 'S') {
                        cout << 0 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << 1 << '\n';
    for (int i=0; i<n; i++) {
        cout << v[i] << '\n';
    }
}