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

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (v[i] >= n) {
            no();
            return;
        }
    }
    vector<int> nop(n + 1);
    vector<int> chk(n + 1);
    for (int i=1; i<=n; i++) {
        if (v[i] == 0 && nop[i] == 0) {
            priority_queue<pi, vector<pi>, greater<pi>> q;
            vector<int> sum;
            q.push({0, i});
            chk[i] = 1;
            while (q.size()) {
                auto [cnt, x] = q.top();
                if (cnt > sum.size()) break;
                chk[x] = 1;
                sum.push_back(x);
                q.pop();
                for (int y : adj[x]) {
                    if (chk[y]) continue;
                    chk[y] = 1;
                    q.push({v[y], y});
                }
            }
            if (sum.size() == n) {
                yes();
                return;
            }
            for (int x : sum) {
                nop[x] = 1;
                chk[x] = 0;
                while (q.size()) {
                    auto [cnt, x] = q.top();
                    chk[x] = 0;
                    q.pop();
                }
            }
        }
    }
    no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}