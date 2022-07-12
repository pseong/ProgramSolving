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

int n;
string s;
const int inf = 1000000000;
int dp[1010];

void solve() {
    cin >> n >> s;
    for (int i=0; i<1010; i++) {
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (s[i] == 'B' && s[j] == 'J' ||
                s[i] == 'O' && s[j] == 'B' ||
                s[i] == 'J' && s[j] == 'O') {
                dp[i] = min(dp[i], dp[j] + (i-j) * (i-j));
            }
        }
    }
    if (dp[n-1] == inf) cout << -1 << '\n';
    else cout << dp[n-1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}