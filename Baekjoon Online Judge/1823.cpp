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

ll dp[2020][2020], v[2020], sum[2020];

ll s(int l, int r) {
    return sum[r] - sum[l-1];
}

ll f(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l == r) return dp[l][r] = v[l];
    return dp[l][r] = max(f(l+1, r) + s(l+1, r) + v[l], f(l, r-1) + s(l, r-1) + v[r]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
    }
    cout << f(1, n) << '\n';
}