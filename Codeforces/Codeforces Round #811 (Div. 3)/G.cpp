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

struct Edge {
    int y, a, b;
};

vector<Edge> adj[202020];
int ans[202020];
vector<ll> now;

void dfs(int x, ll sum) {
    for (auto [y, a, b] : adj[x]) {
        if (now.size()) now.push_back(now.back());
        else now.push_back(0);
        now.back() += b;
        ans[y] = upper_bound(now.begin(), now.end(), sum + a) - now.begin();
        dfs(y, sum + a);
        now.pop_back();
    }
}

void solve(int CASE) {
    int n;
    cin >> n;
    now.clear();
    for (int i=0; i<=n; i++) {
        adj[i].clear();
        ans[i] = 0;
    }
    for (int i=2; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({i, b, c});
    }

    dfs(1, 0);
    for (int i=2; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}