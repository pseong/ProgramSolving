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

const ll mod = 1e9+7;

ll powll(ll n, ll r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    ll x = powll(n, r/2);
    if (r%2 == 0) return x * x % mod;
    return x * x % mod * n % mod;
}

void solve() {
    int n, m; cin >> n >> m;
	int z = 0;
    for (int i=0; i<m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
		z |= x;
    }
    int ans = 0;
    for (int l=0; l<30; l++) {
		if (z&1LL<<l) {
			ans += powll(2, n+l-1);
			ans %= mod;
		}
    }
    cout << ans << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}