#include <bits/stdc++.h>
#define int long long
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

vector<int> adj[1010];
int c[1010], d[1010];
bool prime[2020];

bool dfs(int x) {
    for (int y : adj[x]) {
        if (c[y]) continue;
        c[y] = true;
        if (d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }    
    vector<int> from{-1}, to{-1};
    for (int i=0; i<n; i++) {
        if (v[i]%2 == v.front()%2) {
            from.push_back(v[i]);
        }
        else {
            to.push_back(v[i]);
        }
    }
    for (int i=2; i<(int) from.size(); i++) {
        for (int j=1; j<(int) to.size(); j++) {
            if (prime[from[i] + to[j]] == 0) {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> ans;
    for (int j=1; j<(int) to.size(); j++) {
        if (prime[from[1] + to[j]] == 0) {
            memset(d, 0, sizeof d);
            adj[1].push_back(j);
            for (int i=1; i<(int) from.size(); i++) {
                memset(c, 0, sizeof c);
                if (!dfs(i)) goto g;
            }
            for (int j=1; j<(int) to.size(); j++) {
                if (d[j] == 0) goto g;
            }
            ans.push_back(to[j]);
            g:
            adj[1].pop_back();
        }
    }
    if (ans.empty()) {
        cout << -1 << '\n';
        return;
    }
    srt(ans);
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int x : ans) {
        cout << x << ' ';
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    prime[0] = 1;
    prime[1] = 1;
    for (int i=2; i<=2010; i++) {
        if (prime[i] == 0) {
            for (int j=i+i; j<=2010; j+=i) {
                prime[j] = 1;
            }
        }
    }
    solve();
}