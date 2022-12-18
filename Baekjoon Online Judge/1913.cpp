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

int dx[] {-1, 0, 1, 0};
int dy[] {0, 1, 0, -1};

int v[1010][1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p;
    cin >> n >> p;
    int x = n / 2 + 1;
    int y = n / 2 + 1;
    int go = 1;
    int cnt = 1;
    int left = 1;
    int dir = 0;
    vector<int> ans(2);
    for (int i=1; i<=n*n; i++) {
        if (i == p) {
            ans[0] = x;
            ans[1] = y;
        }
        v[x][y] = i;
        if (left == 0) {
            dir = (dir + 1) % 4;
            if (cnt == 0) {
                go++;
                cnt = 2;
            }
            cnt--;
            left = go;
        }
        left--;
        x += dx[dir];
        y += dy[dir];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}