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

ll v[101010], go[101010], eat[101010], dp[101010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    int j = 0;
    ll sum = 0;
    for (int i=1; i<=n; i++) {
        while (sum < k) {
            j++;
            sum += v[j];
        }
        go[i] = j;
        eat[i] = sum - k;
        sum -= v[i];
    }
    for (int i=1; i<=n; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        dp[go[i]] = max(dp[go[i]], dp[i-1] + eat[i]);
    }
    cout << dp[n] << '\n';
}