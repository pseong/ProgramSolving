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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<vector<ll>> cnt(n, vector<ll>(200001));
    cnt[1][v[1] + 100000] = 1;
    for (int i=2; i<n; i++) {
        for (int j=0; j<=200000; j++) {
            if (j == 100000) {
                cnt[i][v[i] + 100000] = cnt[i-1][j];
            }
            else {
                if (v[i] + j <= 200000) cnt[i][v[i] + j] += cnt[i-1][j], cnt[i][v[i] + j] %= 998244353;
                if (v[i] - j + 200000 <= 200000) cnt[i][v[i] - j + 200000] += cnt[i-1][j], cnt[i][v[i] - j + 200000] %= 998244353;
            }
        }
    }
    ll ans = 0;
    for (int i=0; i<=200000; i++) ans += cnt[n-1][i], ans %= 998244353;
    cout << ans << '\n';
}