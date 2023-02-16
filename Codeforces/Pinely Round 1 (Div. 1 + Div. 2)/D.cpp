#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

const ll mod = 1e9+7;
const ll MAX = 1010101;
ll fact[MAX], p[MAX];

ll powll(ll n, ll r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    ll x = powll(n, r/2);
    if (r%2 == 0) return x * x % mod;
    else return x * x % mod * n % mod;
}

ll comb(ll n, ll r) {
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

    ll n, k;
    cin >> n >> k;
    if (k == 0) {ㅉ
        cout << powll(3, n) << '\n';
        return 0;
    }
    init();
    ll ans = 0;
    for (ll q=1; q<=k; q++) {
        ans += comb(k-1, q-1) * comb(n-k, q) % mod * powll(3, n - q*2) % mod; // 왼쪽 끝을 0이 가져갔을 때
        ans += comb(k-1, q-1) * comb(n-k, q-1) % mod * powll(3, n - q*2 + 1) % mod; // 왼쪽 끝을 1이 가져갔을 때
        ans %= mod;
    }
}