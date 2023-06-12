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
    vector<int> l(n), r(n);
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<int> x = l;
    x.insert(x.end(), r.begin(), r.end());
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i=0; i<n; i++) {
        l[i] = lower_bound(x.begin(), x.end(), l[i]) - x.begin() + 1;
        r[i] = lower_bound(x.begin(), x.end(), r[i]) - x.begin() + 1;
    }
    int z = x.size();
    vector<vector<int>> g(z + 1, vector<int>(z + 1));
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (max(l[i], l[j]) <= min(r[i], r[j])) {
                g[min(l[i], l[j])][max(r[i], r[j])] = 1;
            }
        }
    }
    vector<int> dp(z + 1);
    for (int i=1; i<=z; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        for (int j=1; j<=i; j++) {
            if (g[j][i]) dp[i] = max(dp[i], dp[j-1] + 1);
        }
    }
    cout << n - 2*dp[z] << '\n';
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