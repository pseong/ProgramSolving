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

int n, k;
vector<int> adj[202020];
int dep[202020], p[202020];

void dfs(int x, int d) {
    dep[x] = d;
    for (int y : adj[x]) {
        dfs(y, d + 1);
    }
}

void dis(int x, vector<int>& chk) {
    chk[x] = 1;
    for (int y : adj[x]) {
        if (chk[y]) continue;
        dis(y, chk);
    }
}

bool comp(int x, int y) {
    return dep[x] < dep[y];
}

void solve(int CASE) {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        adj[i].clear();
        dep[i] = 0;
        p[i] = 0;
    }
    for (int i=2; i<=n; i++) {
        int x;
        cin >> x;
        p[i] = x;
        adj[x].push_back(i);
    }
    dfs(1, 0);
    int lo = 1;
    int hi = n;
    int h = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            v[i] = i + 1;
        }
        sort(v.begin(), v.end(), comp);
        vector<int> chk(n + 1);
        int cnt = 0;
        for (int i=n-1; i>=0; i--) {
            if (chk[v[i]]) continue;
            if (cnt >= k) continue;
            if (dep[v[i]] > mid) {
                cnt++;
                int g = v[i];
                for (int j=0; j<mid-1; j++) {
                    g = p[g];
                }
                dis(g, chk);
            }
        }
        bool ok = true;
        for (int i=0; i<n; i++) {
            if (dep[v[i]] > mid && !chk[v[i]]) ok = false;
        }
        if (ok) {
            h = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << h << '\n';
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