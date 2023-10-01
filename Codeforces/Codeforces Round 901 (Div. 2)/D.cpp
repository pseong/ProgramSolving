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
    map<ll, ll> mp;
    for (int i=0; i<n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll mex = 0;
    while (mp[mex]) mex++;
    if (mex == 0) {
        cout << 0 << '\n';
        return;
    }
    vector<ll> dp(mex + 1, 1e18);
    dp[mex] = 0;
    for (int i=mex-1; i>=0; i--) {
        for (int j=i+1; j<=mex; j++) {
            dp[i] = min(dp[i], dp[j] + (mp[i] - 1) * j + i);
        }
    }
    cout << dp[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}