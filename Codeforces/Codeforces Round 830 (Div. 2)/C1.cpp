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

void solve(int CASE) {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    int a, b;
    cin >> a >> b;
    vector<ll> sum(n + 1), xr(n + 1);
    for (int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + v[i];
        xr[i] = xr[i-1] ^ v[i];
    }
    ll l = 1, r = n, mx = 0;
    for (int i=1; i<=n; i++) {
        ll x = (sum[n] - sum[i-1]) - (xr[n] ^ xr[i-1]);
        int lo = i;
        int hi = n;
        int res = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if ((sum[mid] - sum[i-1]) - (xr[mid] ^ xr[i-1]) == x) {
                res = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        if (mx < x) {
            l = i;
            r = res;
        }
        else if (mx == x && res - i < r - l) {
            l = i;
            r = res;
        }
        mx = max(mx, x);
    }
    cout << l << ' ' << r << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}