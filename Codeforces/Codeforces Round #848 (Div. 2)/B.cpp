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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> v(n+1), idx(n+1), a(m);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        idx[v[i]] = i;
    }
    for (int i=0; i<m; i++) {
        cin >> a[i];
    }
    bool ok = true;
    int mn = 1e9;
    for (int i=1; i<m; i++) {
        if (!(idx[a[i]] > idx[a[i-1]] && idx[a[i]] <= idx[a[i-1]] + d)) ok = false;
        else {
            mn = min(mn, idx[a[i]] - idx[a[i-1]]);
            if (d + 1 < n) mn = min(mn, idx[a[i-1]] + d + 1 - idx[a[i]]);
        }
    }
    if (!ok) cout << 0 << '\n';
    else cout << mn << '\n';
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