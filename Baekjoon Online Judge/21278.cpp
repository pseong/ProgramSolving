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

vector<int> adj[110];
int n, m;

vector<int> f(int x) {
    vector<int> chk(n + 1, 1e9);
    chk[x] = 0;
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int a = q.front();
        q.pop();
        for (int b : adj[a]) {
            if (chk[b] != 1e9) continue;
            chk[b] = chk[a] + 1;
            q.push(b);
        }
    }
    return chk;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans{-1, -1, (int)1e9};
    for (int r=1; r<=n; r++) {
        for (int c=1; c<=n; c++) {
            vector<int> dist = f(r);
            vector<int> dist2 = f(c);
            int res = 0;
            for (int i=1; i<=n; i++) res += min(dist[i], dist2[i]);
            res *= 2;
            if (ans[2] > res) {
                ans[0] = r;
                ans[1] = c;
                ans[2] = res;
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}