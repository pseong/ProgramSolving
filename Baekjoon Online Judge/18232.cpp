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

vector<int> adj[303030];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> chk(n + 1, -1);
    queue<int> q;
    q.push(s);
    chk[s] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        vector<int> lst = adj[x];
        lst.push_back(x - 1);
        lst.push_back(x + 1);
        for (int y : lst) {
            if (y < 1 || y > n) continue;
            if (chk[y] != -1) continue;
            chk[y] = chk[x] + 1;
            q.push(y);
        }
    }
    cout << chk[e] << '\n';
}