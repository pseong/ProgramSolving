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

vector<int> adj[202020];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;
    for (int i=0; i<m; i++) {
        for (int j=0; j<k; j++) {
            int a;
            cin >> a;
            adj[i + 101010].push_back(a);
            adj[a].push_back(i + 101010);
        }
    }

    vector<int> chk(202020);
    chk[1] = 1;
    queue<int> q;
    q.push(1);
    int cnt = -1;
    while (q.size()) {
        cnt++;
        int t = q.size();
        while (t--) {
            int x = q.front();
            if (x == n) goto g;
            q.pop();
            for (int y : adj[x]) {
                if (chk[y]) continue;
                chk[y] = 1;
                q.push(y);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
    g:
    cout << cnt / 2 + 1 << '\n';
}