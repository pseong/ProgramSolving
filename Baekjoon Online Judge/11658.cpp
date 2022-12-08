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

int tree[2000][2000];
int n, m;

void update(int x, int y, int p) {
    for (int i=x; i<=n; i+=(i&-i)) {
        for (int j=y; j<=n; j+=(j&-j)) {
            tree[i][j] += p;
        }
    }
}

int query(int x, int y) {
    int res = 0;
    for (int i=x; i>0; i-=(i&-i)) {
        for (int j=y; j>0; j-=(j&-j)) {
            res += tree[i][j];
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
            update(i, j, v[i][j]);
        }
    }
    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            update(x, y, c - v[x][y]);
            v[x][y] = c;
        }
        else {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            cout << query(x, y) + query(a - 1, b - 1) - query(x, b - 1) - query(a - 1, y) << '\n';
        }
    }
}