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

bool prime[10101010];
vector<int> primes;

void solve(int CASE) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    int d = y - x;
    if (d == 0) {
        cout << 0 << '\n';
        return;
    }
    vector<int> fact;
    for (int R : primes) {
        if (d % R != 0) continue;
        fact.push_back(R);
        while (d % R == 0) d /= R;
    }
    if (d != 1) fact.push_back(d);
    int ans = 1e9;
    for (int r : fact) {
        if (r == 1) continue;
        ans = min(ans, (x + r - 1) / r * r - x);
        ans = min(ans, (y + r - 1) / r * r - y);
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=2; i<=3200; i++) {
        if (!prime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<=3200; j+=i) {
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