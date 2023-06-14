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

const ll mod = 998244353;
ll prime[303030];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i=2; i<303030; i++) {
        if (!prime[i]) {
            for (int j=i+i; j<303030; j+=i) {
                prime[j] = 1;
            }
        }
    }

    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    ll mul = 1;
    for (int i=0; i<n; i++) {
        mul = mul * (m % mod) % mod;
        ans = (ans + mul) % mod;
    }
    ll p = 1;
    int cur = 0;
    ll now = 1;
    for (int i=1; i<=n; i++) {
        if (!prime[i]) p *= i;
        if (p > m) break;
        else now = now * (m / p % mod) % mod;
        ans = (ans + mod - now) % mod;
    }
    cout << ans << '\n';
}