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

int v[1010], dp[1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        dp[i] = 1;
    }
    int ans = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << '\n';
}