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
int prime[1010101];

void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cout << primes[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    prime[0] = 1;
    prime[1] = 1;
    for (int i=2; i<=1000000; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<=1000000; j+=i) {
                prime[j] = 1;
            }
        }
    }
    int T; cin >> T;
    while (T--) {
        solve();
    }
}