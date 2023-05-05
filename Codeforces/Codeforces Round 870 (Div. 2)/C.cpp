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

vector<ll> primes;
ll prime[1010101];

void solve(int CASE) {
    ll n, m;
    cin >> n >> m;
    if (n == 1) {
        yes();
        return;
    }
    vector<ll> v;
    for (ll i=2; i*i<=n; i++) {
        if (n%i == 0) {
            v.push_back(i);
            v.push_back(n/i);
            while (n%i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) v.push_back(n);
    sort(v.begin(), v.end());
    if (v.size() && v.front() <= m) {
        no();
    }
    else yes();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=2; i<1010101; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<1010101; j+=i) {
                prime[j] = 1;
            }
        }
    }

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}