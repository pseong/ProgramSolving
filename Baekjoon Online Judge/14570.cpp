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

pi adj[202020];
int ans;

void dfs(int x, ll c) {
    ans = x;
    if (adj[x].first == -1 && adj[x].second == -1) return;
    else if (adj[x].first == -1) dfs(adj[x].second, c);
    else if (adj[x].second == -1) dfs(adj[x].first, c);
    if (c % 2 == 0) dfs(adj[x].second, c / 2);
    else dfs(adj[x].first, (c + 1) / 2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> adj[i].first >> adj[i].second;
    }
    ll k;
    cin >> k;
    int x = 1;
    while (true) {
        ans = x;
        if (adj[x].first == -1 && adj[x].second == -1) break;
        else if (adj[x].first == -1) x = adj[x].second;
        else if (adj[x].second == -1) x = adj[x].first;
        else if (k % 2 == 0) x = adj[x].second, k /= 2;
        else x = adj[x].first, k = (k + 1) / 2;
    }
    cout << ans << '\n';
}