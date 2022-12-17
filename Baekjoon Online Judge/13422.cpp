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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n*2);
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        v[i+n] = v[i];
        sum += v[i];
    }
    if (n == m) {
        if (sum < k) cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    }
    int r = -1;
    int now = 0;
    int ans = 0;
    for (int l=0; l<n; l++) {
        while (r - l + 1 < m) {
            r++;
            now += v[r];
        }
        if (r - l + 1 == m) {
            if (now < k) ans++;
        }
        now -= v[l];
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