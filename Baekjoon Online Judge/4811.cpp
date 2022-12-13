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

ll dp[100];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    dp[0] = 1;
    dp[2] = 1;
    for (int i=4; i<=60; i++) {
        for (int j=0; j<i; j+=2) {
            dp[i] += dp[j] * dp[i-j-2];
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        cout << dp[n*2] << '\n';
    }
}