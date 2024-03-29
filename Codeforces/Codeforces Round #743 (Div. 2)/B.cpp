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
    vector<int> a(n), b(n), p(2*n+1);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
        p[b[i]] = i;
    }
    int ans = 101010;
    int l = n-1;
    for (int i=2*n; i>=1; i--) {
        if (i%2 == 0) {
            l = min(l, p[i]);
        }
        else {
            ans = min(ans, p[i] + l);
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