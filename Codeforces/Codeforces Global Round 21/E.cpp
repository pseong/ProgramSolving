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

const int mod = 1e9+7;
int fact[404040];

int powll(int n, int r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    int x = powll(n, r/2);
    if (r%2 == 0) return x*x%mod;
    return x*x%mod*n%mod;
}
int comb(int n, int r) {
    return fact[n] * powll(fact[n-r]*fact[r]%mod, mod-2) % mod;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    for (int i=0; i<=n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i=0; i<=n; i++) {
        int k = v[i]-1;
        if (k < 0) continue;
        ans += comb(i+k+1, k);
        ans %= mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (int i=1; i<404040; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    solve();
}