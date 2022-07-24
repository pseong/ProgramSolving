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
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    vector<int> cnt(n+1);
    int ans = 100000;
    if (m%2 == 0) ans = 0;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
        ans = min(ans, v[a] + v[b]);
    }
    for (int i=1; i<=n; i++) {
        if (cnt[i]%2 == 1) ans = min(ans, v[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        solve(t);
    }
}