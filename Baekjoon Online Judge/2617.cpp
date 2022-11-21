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

vector<int> adj[1010], rev[1010];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        rev[a].push_back(b);
    }
    int nxt = n / 2;
    int prv = (n - 1) / 2;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int a = 0;
        int b = 0;
        vector<int> chk(n + 1);
        chk[i] = 1;
        queue<int> q;
        q.push(i);
        int cnt = -1;
        while (q.size()) {
            cnt++;
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (chk[y]) continue;
                chk[y] = 1;
                q.push(y);
            }
        }
        if (cnt > nxt) {
            ans++;
            continue;
        }
        chk.assign(n + 1, 0);
        chk[i] = 1;
        q.push(i);
        cnt = -1;
        while (q.size()) {
            cnt++;
            int x = q.front();
            q.pop();
            for (int y : rev[x]) {
                if (chk[y]) continue;
                chk[y] = 1;
                q.push(y);
            }
        }
        if (cnt > prv) {
            ans++;
            continue;
        }
    }
    cout << ans << '\n';
}