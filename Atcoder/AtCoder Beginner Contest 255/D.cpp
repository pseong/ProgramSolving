#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vll v(n+1), pref(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
	for (int i=1; i<=n; i++) {
		pref[i] = pref[i-1] + v[i];
	}

    while (q--) {
        ll x; cin >> x;
        ll idx = lower_bound(v.begin()+1, v.end(), x) - v.begin();
		ll ans = (idx-1)*x - pref[idx-1];
		ans += pref[n] - pref[idx-1] - x*(n-idx+1);
		cout << ans << '\n';
    }
}