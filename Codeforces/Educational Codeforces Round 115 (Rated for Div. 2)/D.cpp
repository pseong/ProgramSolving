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
    vector<int> a(n), b(n), ca(n+1), cb(n+1);
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        ca[a[i]]++;
        cb[b[i]]++;
    }
    int ans = n*(n-1)*(n-2)/6;
    for (int i=0; i<n; i++) {
        ans -= (ca[a[i]] - 1) * (cb[b[i]] - 1);
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