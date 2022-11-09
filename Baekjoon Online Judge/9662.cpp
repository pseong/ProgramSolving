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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    vector<int> dp(n + 100);
    for (int i=0; i<k; i++) {
        cin >> v[i];
        dp[v[i]] = 1;
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<k; j++) {
            if (i - v[j] >= 0 && dp[i - v[j]] == 0) dp[i] = 1;
        }
        if (dp[i] == 0) ans++;
    }
    for (int i=0; i<=n; i++) {
        cout << dp[i] << ' ';
    }
}