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
vector<ll> primes;
bool prime[32000];

void solve(int CASE) {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    ll ans = 1;
    for (int i=1; i<n; i++) {
        if (v[i-1] % v[i] != 0) {
            cout << 0 << '\n';
            return;
        }
        vector<ll> a;
        ll res = m / v[i];
        ll x = v[i-1] / v[i];
        for (ll p : primes) {
            if (p*p > x) break;
            if (x%p == 0) {
                a.push_back(p);
                while (x%p == 0) x /= p;
            }
        }
        if (x != 1) a.push_back(x);
        int s = a.size();
        for (int z=1; z<(1<<s); z++) {
            int cnt = __builtin_popcount(z);
            ll y = 1;
            for (int k=0; k<s; k++) {
                if (z & (1<<k)) y *= a[k];
            }
            if (cnt%2) res -= m / v[i]/y;
            else res += m / v[i]/y;
            // res %= mod;
        }
        ans *= res;
        ans %= mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    prime[0] = 1;
    prime[1] = 1;
    for (int i=2; i<32000; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<32000; j+=i) {
                prime[j] = 1;
            }
        }
    }
    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}