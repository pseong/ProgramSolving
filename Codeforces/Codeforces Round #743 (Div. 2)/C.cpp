#include <bits/stdc++.h>
#define int long long
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
int in[202020];

void solve() {
    int n; cin >> n;
    for (int i=0; i<=n; i++) {
        adj[i].clear();
        in[i] = 0;
    }
    for (int i=1; i<=n; i++) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int a; cin >> a;
            adj[a].push_back(i);
            in[i]++;
        }
    }
    pqg<int> pq;
    for (int i=1; i<=n; i++) {
        if (in[i] == 0) {
            pq.push(i);
        }
    }
    int ans = 0;
    while (pq.size()) {
        ans++;
        pqg<int> pq2;
        while (pq.size()) {
            int x = pq.top(); pq.pop();
            for (int y : adj[x]) {
                if (--in[y] == 0) {
                    if (y > x) {
                        pq.push(y);
                    }
                    else {
                        pq2.push(y);
                    }
                }
            }
        }
        pq = pq2;
    }

    for (int i=1; i<=n; i++) {
        if (in[i]) {
            cout << -1 << '\n';
            return;
        }
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