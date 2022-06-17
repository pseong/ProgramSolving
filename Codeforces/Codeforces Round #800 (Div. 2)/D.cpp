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

vector<int> adj[202020];
pi range[202020];
int ans[202020];

int cnt = 0;
int dfs(int x) {
    ll sum = 0;
    for (int y : adj[x]) {
        sum += dfs(y);
    }
    if (sum < range[x].first) {
        cnt++;
        ans[x] = range[x].second;
    }
    else {
        ans[x] = min(range[x].second, sum);
    }
    return ans[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i=1; i<=n; i++) adj[i].clear();
        cnt = 0;

        for (int i=2; i<=n; i++) {
            int p; cin >> p;
            adj[p].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            cin >> range[i].first >> range[i].second;
        }
        dfs(1);
        cout << cnt << '\n';
    }
}