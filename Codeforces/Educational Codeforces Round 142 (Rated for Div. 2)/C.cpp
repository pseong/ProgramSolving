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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    if (v == v2) {
        cout << 0 << '\n';
        return;
    }
    vector<int> h(n+1);
    for (int i=0; i<n; i++) {
        h[v[i]] = h[v[i]-1] + 1;
    }
    int l = -1;
    int r = -1;
    int ans = n/2;
    for (int i=1; i<=n; i++) {
        l = i - h[i] + 1;
        r = i;
        ans = min(ans, max(l-1, n-r));
    }
    cout << ans << '\n';
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