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

int n, dp[220][220];
string open = "([{";
string close = ")]}";
string str;
const ll MOD = 100000;

ll mod(ll x) {
    if (x >= MOD) return MOD + x%MOD;
    return x;
}

ll f(int s, int e) {
    if (s > e) return 1;
    if (dp[s][e] != -1) return dp[s][e];

    ll ans = 0;
    for (int i=s+1; i<=e; i+=2) {
        for (int t=0; t<3; t++) {
            if (str[s] == open[t] || str[s] == '?') {
                if (str[i] == close[t] || str[i] == '?') {
                    ans += f(s+1, i-1) * f(i+1, e);
                    ans = mod(ans);
                }
            }
        }
    }
    return dp[s][e] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> str;

    ll ans = f(0, n-1);
    if (ans >= MOD) {
        cout.width(5);
        cout.fill('0');
        cout << ans % MOD << '\n';
    }
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}