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

int n, m, ans, v[100][100];

bool chk(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    return v[x][y];
}

void go(int x, int y) {
    if (y == m) {
        y = 0;
        x++;
        if (x == n) {
            ans++;
            return;
        }
    }
    go(x, y+1);
    if (!(chk(x, y-1) && chk(x-1, y) && chk(x-1, y-1))) {
        v[x][y] = 1;
        go(x, y+1);
        v[x][y] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    go(0, 0);
    cout << ans << '\n';
}