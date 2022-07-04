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

int n, h;
vector<int> v;

ll calc(int m) {
    int now = v[0];
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (i == n || v[i] - now >= m) {
            ans += m;
            if (i != n) now = v[i];
        }
        else {
            ans += v[i] - now;
            now = v[i];
        }
    }
    return ans;
}

void solve() {
    cin >> n >> h;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    ll lo = 1;
    ll hi = 1e18;
    ll ans = 1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll cal = calc(mid);
        if (cal >= h) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
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