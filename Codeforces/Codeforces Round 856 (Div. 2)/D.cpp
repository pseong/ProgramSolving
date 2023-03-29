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
ll fact[5050], dp[5050][5050], pl[5050];
vector<ll> p, np;

bool prime(int x) {
    if (x == 0 || x == 1) return false;
    for (int i=2; i*i<=x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

ll powll(ll n, ll r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    ll x = powll(n, r/2);
    if (r%2 == 0) return x * x % mod;
    else return x * x % mod * n % mod;
}
 
ll f(ll x, ll y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == p.size()) return (y == 0);
    ll r = pl[p[x]] * f(x + 1, y) % mod;
    if (y > 0) r += pl[p[x] - 1] * f(x + 1, y - 1);
    r %= mod;
    return dp[x][y] = r;
}
 
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    for (ll i=0; i<5050; i++) {
        for (ll j=0; j<5050; j++) {
            dp[i][j] = -1;
        }
    }
    fact[0] = 1;
    for (ll i=1; i<5050; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    for (int i=0; i<5050; i++) {
        pl[i] = powll(fact[i], mod-2);
    }
    ll n;
    cin >> n;
    vector<ll> v(n*2);
    map<ll, ll> mp, mp2;
    for (ll i=0; i<n*2; i++) {
        cin >> v[i];
        if (prime(v[i])) mp[v[i]]++;
        else mp2[v[i]]++;
    }
    for (auto [x, y] : mp) p.push_back(y);
    for (auto [x, y] : mp2) np.push_back(y);
    ll ans = fact[n];
    for (ll i=0; i<(ll)np.size(); i++) {
        ans *= powll(fact[np[i]], mod-2);
        ans %= mod;
    }
    ans *= f(0, n);
    ans %= mod;
    cout << ans << '\n';
}