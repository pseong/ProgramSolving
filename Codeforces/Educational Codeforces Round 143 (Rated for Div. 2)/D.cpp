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
const ll MAX = 303030;
ll fact[MAX], p[MAX];

ll powll(int n, int r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    ll x = powll(n, r/2);
    if (r%2 == 0) return x * x % mod;
    else return x * x % mod * n % mod;
}

ll comb(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * p[n-r] % mod * p[r] % mod;
}

void init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    for (int i=0; i<MAX; i++) {
        p[i] = powll(fact[i], mod-2);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    vector<ll> c(n/3);
    ll ans = 1;
    for (int i=0; i<n; i+=3) {
        vector<ll> x{v[i] + v[i+1], v[i] + v[i+2], v[i+1] + v[i+2]};
        sort(x.begin(), x.end());
        ans *= count(x.begin(), x.end(), x.back());
        ans %= mod;
    }
    init();
    ans *= comb(n/3, n/6);
    ans %= mod;
    cout << ans << '\n';
}