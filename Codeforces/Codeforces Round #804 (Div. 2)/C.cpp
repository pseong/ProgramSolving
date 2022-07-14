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

const ll mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j=0; j<n; j++){
        cin >> a[j];
    }
    vector<int> p(n);
    for (int j=0; j<n; j++){
        p[a[j]] = j;
    }
    int r = p[0];
    int l = p[0];
    ll ans = 1;
    for (int j=1; j<n; j++){
        if (p[j] < l) {
            l = p[j];
        }
        else if (p[j] > r) {
            r = p[j];
        }
        else {
            ans *= (r - l - j + 1);
            ans %= mod;
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