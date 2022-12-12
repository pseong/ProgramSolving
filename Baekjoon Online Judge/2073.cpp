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

bool dp[400][101010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int d, p;
    cin >> d >> p;
    vector<pi> v(p);
    for (int i=0; i<p; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.rbegin(), v.rend());
    dp[0][0] = 1;
    for (int i=0; i<p; i++) {
        auto [c, l] = v[i];
        int now = i + 1;
        for (int j=0; j<=d; j++) {
            dp[now][j] = dp[now-1][j];
        }
        for (int j=l; j<=d; j++) {
            if (dp[now-1][j-l]) dp[now][j] = 1;
        }
        if (dp[now][d]) {
            cout << c << '\n';
            return 0;
        }
    }
}