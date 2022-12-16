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

vector<int> adj[550];
int in[550], dp[550], v[550];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        dp[i] = v[i];
        while (true) {
            int a;
            cin >> a;
            if (a == -1) break;
            adj[a].push_back(i);
            in[i]++;
        }
    }
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (in[i] == 0) q.push(i);
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            dp[y] = max(dp[y], dp[x] + v[y]);
            if (--in[y] == 0) q.push(y);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << dp[i] << '\n';
    }
}