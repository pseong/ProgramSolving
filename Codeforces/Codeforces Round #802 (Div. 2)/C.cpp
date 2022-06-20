#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n; cin >> n;
    vector<ll> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    int ans = 0;
	int now = v[1], late = 0;
    for (int i=1; i<n; i++) {
		int diff = abs(v[i+1] - v[i]);
        if (v[i]+late < v[i+1]+late) {
            late -= diff;
        }
        else if (v[i]+late > v[i+1]+late) {
			now -= diff;
        }
		ans += diff;
    }
    ans += abs(now);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}