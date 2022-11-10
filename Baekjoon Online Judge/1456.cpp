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

int prime[10101010];
vector<int> primes;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;

    for (int i=2; i<=1e7; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<=1e7; j+=i) {
                prime[j] = 1;
            }
        }
    }

    int ans = 0;
    for (ll p : primes) {
        ll go = p;
        while (go <= b / p) {
            go *= p;
            if (go >= a) ans++;
        }
    }

    cout << ans << '\n';
}