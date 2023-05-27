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

const ll mod = 1e9 + 7;
const ll MAX = 202020;
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

ll cnt[202020];
vector<int> adj[202020];
ll n, k, ans;

void cal(int x, int p) {
    for (int y : adj[x]) {
        if (p == y) continue;
        cal(y, x);
        cnt[x] += cnt[y];
    }
    cnt[x]++;
}

void two(int x, int p) {
    ans += comb(n, 2);
    ans %= mod;
    ans -= comb(n-cnt[x], 2);
    if (ans < 0) ans += mod;
    for (int y : adj[x]) {
        if (y == p) continue;
        ans -= comb(cnt[y], 2);
        if (ans < 0) ans += mod;
        ans %= mod;
        two(y, x);
    }
}

void three(int x, int p) {
    ans += comb(n-1, 3) + comb(n-1, 2);
    ans %= mod;
    ans -= comb(n-cnt[x], 3);
    if (ans < 0) ans += mod;
    ans -= comb(n-cnt[x], 2) * (cnt[x] - 1) % mod;
    if (ans < 0) ans += mod;
    ans -= comb(n-cnt[x], 2);
    if (ans < 0) ans += mod;
    for (int y : adj[x]) {
        if (y == p) continue;
        ans -= comb(cnt[y], 2) * (n - 1 - cnt[y]) % mod;
        if (ans < 0) ans += mod;
        ans -= comb(cnt[y], 3) % mod;
        if (ans < 0) ans += mod;
        ans -= comb(cnt[y], 2);
        if (ans < 0) ans += mod;
        three(y, x);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    init();
    cal(1, 0);

    if (k == 1) {
        cout << 1 << '\n';
    }
    else if (k == 2) {
        two(1, 0);
        if (ans < 0) ans += mod;
        ans %= mod;
        cout << ans * powll(comb(n, 2), mod-2) % mod << '\n';
    }
    else if (k == 3) {
        three(1, 0);
        if (ans < 0) ans += mod;
        ans %= mod;
        cout << ans * powll(comb(n, 3), mod-2) % mod << '\n';
    }
}