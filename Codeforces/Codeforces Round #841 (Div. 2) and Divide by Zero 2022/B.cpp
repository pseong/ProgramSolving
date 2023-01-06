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
 
ll mod = 1e9 + 7;
 
ll powll(ll x, ll p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    ll y = powll(x, p/2);
    if (p%2 == 0) return y * y % mod;
    else return y * y % mod * x % mod;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll res = n * (n+1) % mod * (2*n % mod + 1) % mod * powll(3, mod-2) % mod - n * (n+1) % mod  * powll(2, mod-2) % mod;
        while (res < 0) res += mod;
        cout << res * 2022 % mod << '\n';
    }
}