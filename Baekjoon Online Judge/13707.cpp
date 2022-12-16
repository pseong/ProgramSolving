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

const ll mod = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int x = n + k - 1;
    // x C n 구하기
    vector<ll> dp(5050);
    dp[1] = 1;
    for (int i=2; i<=x+1; i++) {
        vector<ll> tmp(5050);
        for (int j=1; j<=i; j++) {
            tmp[j] = dp[j-1] + dp[j];
            tmp[j] %= mod;
        }
        dp = tmp;
    }
    cout << dp[n+1] << '\n';
}