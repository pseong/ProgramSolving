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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, y;
    cin >> n >> x >> y;
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(x);
    vector<int> chk(110);
    chk[x] = 1;
    while (q.size()) {
        int a = q.front();
        q.pop();
        for (int b : adj[a]) {
            if (chk[b]) continue;
            chk[b] = chk[a] + 1;
            q.push(b);
        }
    }
    cout << chk[y] - 1 << '\n';
}