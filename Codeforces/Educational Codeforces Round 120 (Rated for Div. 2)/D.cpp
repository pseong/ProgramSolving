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
const ll MAX = 5050;
ll fact[MAX], p[MAX];

ll powll(int n, int r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    ll x = powll(n, r/2);
    if (r%2 == 0) return x * x % mod;
    else return x * x % mod * n % mod;
}

ll comb(int n, int r) {
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

void solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    s.insert(s.begin(), 'X');
    vector<ll> pref(n+1);
    for (ll i=1; i<=n; i++) {
        pref[i] = pref[i-1] + s[i] - '0';
    }
    if (pref[n] < k) {
        cout << 1 << '\n';
        return;
    }

    ll ans = 1;
    for (ll i=1; i<=n; i++) {
        for (ll j = i+1; j<=n; j++) {
            ll cnt = j - i + 1;
            ll cnt1 = pref[j] - pref[i-1];
            if (cnt1 > k) continue;
            if (s[i] == '0') cnt1--;
            if (s[j] == '0') cnt1--;
            if (cnt1 >= 0 && cnt1 <= cnt) {
                ans += comb(cnt-2, cnt1);
                ans %= mod;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    solve();
}