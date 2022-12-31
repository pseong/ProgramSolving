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

ll cal(ll n) {
    if (n == 1) return 0;
    ll res = 0;
    for (int i=1; i*i<=n; i++) {
        if (n % i == 0) {
            res += i;
            if (i * i != n && i != 1) res += n / i;   
        }
    }
    return res;
}

void solve(int CASE) {
    ll n;
    cin >> n;
    ll a = cal(n);
    if (cal(n) <= n) {
        cout << "BOJ 2022\n";
        return;
    }
    for (int i=1; i*i<=n; i++) {
        if (n % i == 0) {
            if (cal(i) > i || n / i != n && cal(n / i) > n / i) {
                cout << "BOJ 2022\n";
                return;
            }
        }
    }
    cout << "Good Bye\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}