#include <bits/stdc++.h>
#define int long long
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

const int mod = 998244353;
int fact[260000];

int powll(int n, int r) {
    if (r == 0) return 1;
    if (r == 1) return n % mod;
    int x = powll(n, r/2) % mod;
    if (r % 2) return x * x % mod * n % mod;
    else return x * x % mod;
}
int comb(int n, int r) {
    return fact[n] * powll(fact[n-r] * fact[r] % mod, mod-2) % mod;
}

void solve() {
    int n;
    cin >> n;
    int ans = fact[n*n];
    for (int i=n; i<=n*n-n+1; i++) {
        int a = comb(i-1, n-1);
        int b = comb(n*n-i, n-1);

        int minus = a * b % mod * fact[n-1] % mod * fact[n-1] % mod * n % mod * n % mod * fact[(n-1)*(n-1)] % mod;
        ans -= minus;
        if (ans < 0) {
            int cnt = (-ans) / mod;
            ans += mod * (cnt+10);
        }
        ans %= mod;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x = 1;
    fact[0] = 1;
    for (int i=1; i<260000; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    solve();
}