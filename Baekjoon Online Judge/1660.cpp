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

ll dp[303030];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v;
    int cur = 0;
    int cur2 = 0;
    int cur3 = 0;
    int now = 0;
    while (true) {
        cur++;
        cur2 += cur;
        now += cur2;
        if (now > 300000) break;
        v.push_back(now);
    }
    fill(dp, dp+303030, 1e9);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        for (int x : v) {
            if (i - x < 0) break;
            dp[i] = min(dp[i], dp[i-x] + 1);
        }
    }
    cout << dp[n] << '\n';
}