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
 
vector<int> adj[101010];
int dp[101010], mx[101010];
 
void go(int x) {
    mx[x] = 1;
    for (int y : adj[x]) {
        go(y);
        dp[x] += dp[y];
        mx[x] = max(mx[x], mx[y] + 1);
    }
    dp[x] = max(dp[x], mx[x]);
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    go(1);
    cout << dp[1] << '\n';
}