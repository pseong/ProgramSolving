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

vector<int> primes;

bool prime(int x) {
    for (int i=2; i*i<=x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

ll dp[40404];
const ll mod = 123456789;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (prime(i)) primes.push_back(i);
    }
    dp[0] = 1;
    for (int x : primes) {
        for (int i=0; i<=n; i++) {
            if (i-x >= 0) dp[i] += dp[i-x];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << '\n';
}