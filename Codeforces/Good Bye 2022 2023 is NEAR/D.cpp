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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), chk(n + 1), vis(n + 1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    vector<vector<int>> adj(n + 1);
    const ll mod = 998244353;
    ll ans = 1;
    for (int i=1; i<=n; i++) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
        if (a[i] == b[i]) chk[a[i]] = 1;
    }
    for (int i=1; i<=n; i++) {
        if (vis[i] == 0) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            while (q.size()) {
                int x = q.front();
                cnt1++;
                cnt2 += adj[x].size();
                if (chk[x]) cnt3++;
                q.pop();
                for (int y : adj[x]) {
                    if (vis[y]) continue;
                    vis[y] = 1;
                    q.push(y);
                }
            }
            if (cnt2 != cnt1 * 2) {
                cout << 0 << '\n';
                return;
            }
            if (cnt3) ans *= n;
            else ans *= 2;
            ans %= mod;
        }
    }
    cout << ans << '\n';
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