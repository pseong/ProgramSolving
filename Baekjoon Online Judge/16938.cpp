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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int k=0; k<(1<<n); k++) {
        int mx = 0;
        int mn = 1e9;
        int sum = 0;
        for (int i=0; i<n; i++) {
            if (k & (1<<i)) {
                mx = max(mx, v[i]);
                mn = min(mn, v[i]);
                sum += v[i];
            }
        }
        if (sum >= l && sum <= r && mx - mn >= x) ans++;
    }
    cout << ans << '\n';
}