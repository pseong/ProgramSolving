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

int pal[5050][5050], v[5050], dp[5050];
int n;

int f(int x) {
    if (dp[x] != -1) return dp[x];
    if (x > n) return 0;
    dp[x] = 0;
    for (int i=x+1; i<=n; i+=2) {
        if (pal[x][i]) {
            int ret = f(i+1);
            if (i == n || ret != 0) dp[x] = max(dp[x], ret + 1);
        }
    }
    return dp[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<n; i++) {
        int l = i;
        int r = i + 1;
        while (l >= 1 && r <= n && v[l] == v[r]) {
            pal[l][r] = 1;
            l--;
            r++;
        }
    }
    memset(dp, -1, sizeof dp);
    if (f(1) == 0) cout << -1 << '\n';
    else cout << f(1) << '\n';
}