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
int cnt[30];

ll powll(ll n, ll r) {
	if (r == 0) return 1;
	if (r == 1) return n;
	ll x = powll(n, r/2);
	if (r%2 == 0) return x * x % mod;
	return x * x % mod * n % mod;
}
void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        int x = 0;
        for (int k = 0; k < 30; k++){
            if(a[i] & 1)break;
            a[i] >>= 1;
            x++;
        }
        cnt[x]++;
    }

    int ans = powll(2, n) - powll(2, n-cnt[0]) + mod;
	ans %= mod;

    int y = n-cnt[0];

    for (int l = 1; l < 30; l++){
        int x = y;
        y -= cnt[l];
        if (cnt[l] == 0) continue;
        int delta = powll(2, x-1) - powll(2, y) + mod;
        ans += delta;
		ans %= mod;
    }

    cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}