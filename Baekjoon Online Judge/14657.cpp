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

vector<pi> adj[50505];
int dp[50505][2];
vector<int> ans{0, 100000000};

bool comp(pi& a, pi& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

void go(int x, int p) {
    vector<pi> v;
    for (auto [y, c] : adj[x]) {
        if (y == p) continue;
        go(y, x);
        v.push_back({dp[y][0], dp[y][1] + c});
    }
    sort(v.begin(), v.end(), comp);
    dp[x][0] = 1;
    if (v.size()) {
        dp[x][0] += v[0].first;
        dp[x][1] = v[0].second;
    }
    int len = 1;
    int t = 0;
    if (v.size() >= 1) {
        len += v[0].first;
        t += v[0].second;
    }
    if (v.size() >= 2) {
        len += v[1].first;
        t += v[1].second;
    }
    if (ans[0] < len) {
        ans[0] = len;
        ans[1] = t;
    }
    else if (ans[0] == len) ans[1] = min(ans[1], t);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    go(1, 0);
    cout << (ans[1] + t - 1) / t << '\n';
}