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

int dp[202020];
pi hist[202020];
vector<pi> v;

void cal() {
    int i=2;
    while (true) {
        int x = i*(i-1)/2;
        v.push_back({x, i});
        if (x > 200000) break;
        i++;
    }
    for (int i=0; i<202020; i++) dp[i] = 1e9;
    dp[0] = 0;
    for (int i=0; i<(int)v.size(); i++) {
        for (int j=0; j<=200000; j++) {
            if (j + v[i].first <= 200000 && dp[j + v[i].first] > dp[j] + v[i].second) {
                dp[j + v[i].first] = dp[j] + v[i].second;
                hist[j + v[i].first] = {j, v[i].second};
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cal();
    int p;
    cin >> p;
    ll cnt = dp[p];
    ll ans = cnt * (cnt - 1) / 2 - p;
    cout << cnt << ' ' << ans << '\n';
}