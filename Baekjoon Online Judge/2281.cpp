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

int n, m;
int v[1010], dp[1010];
const int inf = 1000000000;

int f(int i) {
    if (i > n) return 0;
    if (dp[i] != inf) return dp[i];
    int ans = inf;
    int cnt = m - v[i];
    for (int j=i+1; j<=n+1; j++) {
        if (cnt < 0) break;
        if (j == n+1) ans = 0;
        else ans = min(ans, f(j) + cnt*cnt);
        cnt -= 1 + v[j];
    }
    return dp[i] = ans;
}

void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<1010; i++) {
        dp[i] = inf;
    }
    cout << f(1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}