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

int a[1010], b[1010], dp[1010][1010];
int n, m;
const int inf = 2e9;

int f(int x, int y) {
    if (dp[x][y] != inf) return dp[x][y];
    if (x == 0 || y == 0) return 0;
    for (int i=y; i>=x; i--) {
        dp[x][y] = min(dp[x][y], f(x-1, i-1) + abs(a[x] - b[i]));
    }
    for (int i=x; i>=y; i--) {
        dp[x][y] = min(dp[x][y], f(i-1, y-1) + abs(a[i] - b[y]));
    }
    return dp[x][y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    fill(&dp[0][0], &dp[1009][1010], inf);
    cout << f(n, m) << '\n';
}