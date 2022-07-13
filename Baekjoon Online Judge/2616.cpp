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

ll dp[50505][4];
ll an[50505], pref[50505];
int n, m;

void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        pref[i] = pref[i-1] + an[i];
    }
    cin >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=3; j++) {
            dp[i][j] = max(dp[i-1][j], dp[max(0, i-m)][j-1] + pref[i] - pref[max(0, i-m)]);
        }
    }
    cout << dp[n][3];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}