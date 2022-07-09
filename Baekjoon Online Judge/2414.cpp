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

vector<int> adj[3500];
string s[100];
int mark[100][100][2];
int c[3500], d[3500];

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
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt++;
        for (int j=0; j<m; j++) {
            if (s[i][j] == '.') {
                cnt++;
                continue;
            }
            mark[i][j][0] = cnt;
        }
    }

    cnt = 0;
    for (int j=0; j<m; j++) {
        cnt++;
        for (int i=0; i<n; i++) {
            if (s[i][j] == '.') {
                cnt++;
                continue;
            }
            mark[i][j][1] = cnt;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == '.') continue;
            adj[mark[i][j][0]].push_back(mark[i][j][1]);
        }
    }

    int ans = 0;
    for (int i=1; i<=n*m; i++) {
        memset(c, 0, sizeof c);
        if (dfs(i)) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}