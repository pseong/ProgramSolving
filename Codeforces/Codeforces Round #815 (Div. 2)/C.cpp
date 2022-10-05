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

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    bool go = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == '1') cnt++;
            else {
                for (int d=0; d<8; d++) {
                    int x = i+dx[d];
                    int y = j+dy[d];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (v[x][y] == '0') go = true;
                }
            }
        }
    }
    if (go) cout << cnt << '\n';
    else if (cnt == n * m) cout << n * m - 2 << '\n';
    else cout << cnt - 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}