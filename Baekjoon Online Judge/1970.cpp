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

int n, an[1010], dp[1010][1010];

int f(int s, int e) {
    if (s >= e) return 0;
    if (dp[s][e] != -1) return dp[s][e];
    int ans = 0;
    for (int i=s+1; i<=e; i++) {
        if (an[s] == an[i]) {
            ans = max(ans, 1 + f(s+1, i-1) + f(i+1, e));
        }
    }
    ans = max(ans, f(s+1, e));
    return dp[s][e] = ans;
}

void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }

    memset(dp, -1, sizeof dp);
    cout << f(1, n) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}