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

ll inf = 999999999999999;
ll dp[110]{0, inf, 1, 7, 4, 2, 6, 8};
vector<ll> v{0, 0, 1, 7, 4, 2, 0, 8};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=8; i<=100; i++) {
        dp[i] = inf;
    }
    for (int i=8; i<=100; i++) {
        for (int j=2; j<=7; j++) {
            dp[i] = min(dp[i], dp[i-j] * 10 + v[j]);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << ' ';
        if (n % 2 == 1) cout << "7", n -= 3;
        cout << string(n / 2, '1') << '\n';
    }
}