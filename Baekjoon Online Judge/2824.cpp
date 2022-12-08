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
    
    int n;
    cin >> n;
    vector<ll> a(n);
    int big = 0;
    const int mod = 1000000000;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<ll> b(m);
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    ll ans = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ll g = gcd(a[i], b[j]);
            ans *= g;
            a[i] /= g;
            b[j] /= g;
            if (ans >= mod) {
                big = 1;
                ans %= mod;
            }
        }
    }
    if (big) cout << setw(9) << setfill('0') << ans << '\n';
    else cout << ans << '\n';
}