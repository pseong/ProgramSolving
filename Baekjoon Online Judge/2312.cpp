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

vector<int> primes, prime(101010, 1);

void solve(int CASE) {
    int n;
    cin >> n;
    vector<pi> ans;
    for (int p : primes) {
        int cnt = 0;
        while (n % p == 0) {
            cnt++;
            n /= p;
        }
        if (cnt) ans.push_back({p, cnt});
    }
    for (int i=0; i<(int)ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=2; i<=100000; i++) {
        if (prime[i] == 1) {
            primes.push_back(i);
            for (int j=i+i; j<=100000; j+=i) {
                prime[j] = 0;
            }
        }
    }

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}