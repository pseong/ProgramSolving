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

vector<int> adj[1010];
int chk[1010][1010], c[1010];
vector<vector<int>> lst;
bool fail;

void go(int x) {
    vector<int> p(2);
    queue<int> q;
    q.push(x);
    c[x] = 1;
    int now = 2;
    while (q.size()) {
        int t = q.size();
        while (t--) {
            int y = q.front();
            q.pop();
            p[now - 1]++;
            for (int z : adj[y]) {
                if (c[z]) {
                    if (c[z] != now) fail = true;
                    continue;
                }
                c[z] = now;
                q.push(z);
            }
        }
        now = 3 - now;
    }
    lst.push_back(p);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        chk[a][b] = 1;
        chk[b][a] = 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) continue;
            if (chk[i][j] == 0) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (c[i] == 0) {
            go(i);
        }
    }
    if (fail) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> poss(n + 1);
    poss[0] = 1;
    for (int i=0; i<(int)lst.size(); i++) {
        vector<int> tmp(n + 1);
        for (int k=0; k<2; k++) {
            for (int j=0; j<=n; j++) {
                if (poss[j] && j + lst[i][k] <= n) tmp[j + lst[i][k]] = 1;
            }
        }
        poss = tmp;
    }
    int ans = 1000;
    for (int i=0; i<=n; i++) {
        if (poss[i]) {
            ans = min(ans, abs(n - i * 2));
        }
    }
    cout << ans << '\n';
}