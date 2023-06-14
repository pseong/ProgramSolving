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

const i128 mod = 998244353;
i128 prime[303030];
vector<i128> primes;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i=2; i<303030; i++) {
        if (!prime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<303030; j+=i) {
                prime[j] = 1;
            }
        }
    }

    ll N, M;
    cin >> N >> M;
    i128 n = N, m = M;
    i128 ans = 0;
    i128 mul = 1;
    for (int i=0; i<n; i++) {
        mul *= m;
        mul %= mod;
        ans += mul;
        ans %= mod;
    }
    i128 p = 1;
    int cur = 0;
    vector<i128> dp(n + 1);
    dp[1] = m;
    ans -= m % mod;
    if (ans < 0) ans += mod;
    ans %= mod;
    for (int i=2; i<=n; i++) {
        if (primes[cur] <= i) {
            p *= primes[cur];
            cur++;
        }
        if (p > m) break;
        else {
            dp[i] = dp[i-1] * (m / p % mod) % mod;
        }
        ans -= dp[i];
        if (ans < 0) ans += mod;
        ans %= mod;
    }
    cout << (ll)ans << '\n';
}