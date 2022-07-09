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

vector<int> adj[7000];

int dx[]{-1, -1, 0, 0, 1, 1};
int dy[]{-1, 1, -1, 1, -1, 1};
string v[100];
int n, m;

void add(int x, int y) {
    for (int d=0; d<6; d++) {
        int i = x+dx[d];
        int j = y+dy[d];
        if (i < 0 || i >= n || j < 0 || j >= m) continue;
        if (v[i][j] == 'x') continue;
        adj[x*m+y+1].push_back(i*m+j+1);
    }
}

int c[7000], d[7000];

bool dfs(int x) {
    for (int y : adj[x]) {
        if (c[y]) continue;
        c[y] = true;
        if (d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<7000; i++) {
        adj[i].clear();
        d[i] = 0;
    }
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (j%2 == 0) {
                if (v[i][j] == '.') {
                    add(i, j);
                }
            }
        }
    }
    int ans = n*m;
    for (int i=1; i<=n*m; i++) {
        int x = i-1;
        if (v[x/m][x%m] == 'x') {
            ans--;
            continue;
        }
        memset(c, 0, sizeof c);
        if (dfs(i)) ans--;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}