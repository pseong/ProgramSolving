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

ll fact[5050], comb[5050][5050];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, p;
    cin >> n >> p;
    fact[0] = 1;
    for (int i=1; i<=5000; i++) {
        fact[i] = fact[i-1] * i % p;
    }
    comb[0][0] = 1;
    for (int i=1; i<=5000; i++) {
        comb[i][0] = 1;
        for (int j=1; j<=i; j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
            comb[i][j] %= p;
        }
    }
    ll ans = 0;
    ll c = n/2;
    for (ll i=n/2; i<=n-2; i++) {
        for (ll j=0; j<=n-i-2; j++) {
            ans += n * comb[n-i-2][j] % p * fact[i+j-1] % p * c % p;
            ans %= p;
        }
        c--;
    }
    if (n%2 == 0) ans += n * fact[n-2] % p;
    ans %= p;
    cout << ans << '\n';
}