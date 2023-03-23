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

ll sum[1010101];

void solve(int CASE) {
    int n, x, p;
    cin >> n >> x >> p;
    int m = (n - x) % n;
    for (int i=1; i<=min(n*10, p); i++) {
        if (sum[i] % n == m) {
            yes();
            return;
        }
    }
    no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=1; i<=1000000; i++) {
        sum[i] = sum[i-1] + i;
    }

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}